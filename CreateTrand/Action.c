#include <stdlib.h>
#include <time.h> 

int totalTests;
int selectedIndex;
int projectCount;
int count = 0;
int index1 = 0;
int index2 = 0;
char projectId[32];
char paramName[64];
char trendNumberStr[16];
int trendNumber;
Action()
{
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_url("authorize", 
		"URL=https://dev-boomq.pflb.ru/authorize", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML",
		LAST);

	lr_start_transaction("UC_03_TR_01_sign_in");

	web_add_header("Origin", "https://dev-boomq.pflb.ru");

	lr_think_time(5);

	web_set_max_html_param_len("4096");
	
	web_reg_save_param("auth_token",
     	"LB=boomq_auth=",
     	"RB=;",
     	"Search=Headers",
     	"Ordinal=1",
    	LAST);
    
	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={user}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);
	
	lr_output_message("========= TOKEN =========: %s", lr_eval_string("{auth_token}"));
	
	web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token}"));
	
	web_add_cookie("boomq_auth={auth_token}; DOMAIN=dev-boomq.pflb.ru");
	
	web_reg_save_param_json(
		"ParamName=user_id",
		"QueryString=$.id",
		SEARCH_FILTERS,
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param(
        "auth_token_new",
        "LB=set-cookie: boomq_auth=",
        "RB=\r\n",
        "Search=Headers",
        LAST);
	
	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_03_TR_01_sign_in",LR_AUTO);

	lr_start_transaction("1_transactionсоздание тренда");
	
web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token_new}"));
        
		web_url("slaReportProfile", 
		"URL=https://dev-boomq.pflb.ru/account/slaReportProfile", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/arrow.659530470e6be7b696f0d3d15a3179f5.svg", "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", ENDITEM, 
		"Url=../static/media/arrow_down.6be88730f13ef3a159f4ef4438670da1.svg", "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", ENDITEM, 
		LAST);

        web_reg_save_param_json(
    "ParamName=projectIdList",
    "QueryString=$..id",
    "SelectAll=Yes",
    LAST); 
	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
projectCount = atoi(lr_eval_string("{projectIdList_count}"));
lr_output_message("Найдено проектов: %d", projectCount);

if (projectCount < 1) {
    lr_error_message("Не найдено ни одного проекта!");
    lr_exit(LR_EXIT_VUSER, LR_FAIL);
}
	lr_think_time(4);
	

	do {
    selectedIndex = (rand() % projectCount) + 1; // Индексы с 1 до projectCount

    snprintf(projectId, sizeof(projectId), "{projectIdList_%d}", selectedIndex);
    lr_save_string(lr_eval_string(projectId), "currentProjectId");
    lr_output_message("Проверяем проект с ID: %s", lr_eval_string("{currentProjectId}"));
	
    web_reg_save_param_json(
    "ParamName=TotalElements",
    "QueryString=$..numberOfElements", 
     LAST);
    
	web_url("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&size=999999&projectId={currentProjectId}&state=FINISHED,FAILED,CANCELED", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);
	
    totalTests = atoi(lr_eval_string("{TotalElements}"));
    lr_output_message("Количество тестов в проекте: %d", totalTests);

    if (totalTests < 2) {
        lr_output_message("В проекте слишком мало тестов (%d), выбираем другой проект...", totalTests);
        lr_think_time(2);
    }

} while (totalTests < 2);

lr_output_message("Выбран проект %s с %d тестами.", lr_eval_string("{currentProjectId}"), totalTests);

 web_reg_save_param_json(
        "ParamName=IdList",
        "QueryString=$.content[*].id",
        "SelectAll=Yes",
        LAST);
    
	web_url("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&size=999999&projectId={currentProjectId}&state=FINISHED,FAILED,CANCELED", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);
count = atoi(lr_eval_string("{IdList_count}"));
srand(time(NULL));

index1 = (rand() % count) + 1;
do {
    index2 = (rand() % count) + 1;
} while (index2 == index1);


snprintf(paramName, sizeof(paramName), "IdList_%d", index1);
lr_save_string(lr_eval_string(paramName), "index1");

snprintf(paramName, sizeof(paramName), "IdList_%d", index2);
lr_save_string(lr_eval_string(paramName), "index2");



lr_output_message("Выбраны случайные ID: %s и %s", 
                  lr_eval_string("{index1}"),
                  lr_eval_string("{index2}"));
	


	web_add_auto_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(6);

	web_custom_request("slaTypeList", 
    "URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/slaTypeList", 
    "Method=POST", 
    "Resource=0", 
    "RecContentType=application/json", 
    "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
    "Snapshot=t15.inf", 
    "Mode=HTML", 
    "EncType=application/json", 
    "Body={\"projectId\":{currentProjectId},\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}],\"chartProfileList\":[],\"tableProfileList\":[]}", 
    LAST);


	web_custom_request("previewReport_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}]}],\"testFilterExpressionList\":[{\""
		"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\","
		"\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_5", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\""
		"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_6", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\""
		"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	lr_think_time(10);

	web_custom_request("previewReport_7", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_8", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_9", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_10", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	web_custom_request("previewReport_11", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":{currentProjectId},\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\""
		":[{index1},{index2}]}]}", 
		LAST);

	lr_think_time(4);

	srand(time(NULL));
    trendNumber = 1000 + rand() % 9000; 
    sprintf(trendNumberStr, "%d", trendNumber);
    lr_save_string(trendNumberStr, "trendNumber");
lr_output_message("Сгенерированное имя тренда (число): %s", lr_eval_string("{trendNumber}"));

	web_custom_request("slaReportProfile_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"name\":\"trend_{trendNumber}\",\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}],\"orderInReport\":0}],\"tableProfileList\":[{\"tableId\":null,\"slaTypeList\":[{\"fromDate\":8,\""
		"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13"
		",\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\",\"orderInReport\":1}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[{index1},{index2}]}]}", 
		LAST);

	lr_end_transaction("1_transactionсоздание тренда",LR_AUTO);

	return 0;
}