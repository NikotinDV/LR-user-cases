Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Microsoft Edge\";v=\"135\", \"Not-A.Brand\";v=\"8\", \"Chromium\";v=\"135\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("authorize", 
		"URL=https://dev-boomq.pflb.ru/authorize", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", ENDITEM, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2025-05-21T13:48:20.902Z");

	lr_think_time(5);

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=nagruzka3_gr01@mail.com", ENDITEM, 
		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=25", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("user_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"Body={\"email\":\"nagruzka3_gr01@mail.com\",\"id\":5881,\"language\":\"EN\",\"notificationEnabled\":false}", 
		LAST);

	web_url("25", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/25", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(10);

	lr_start_transaction("1_transactionñîçäàíèå òðåíäà");

	web_url("slaReportProfile", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/arrow.659530470e6be7b696f0d3d15a3179f5.svg", "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", ENDITEM, 
		LAST);

	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/arrow_down.6be88730f13ef3a159f4ef4438670da1.svg", "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_url("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&size=999999&projectId=7571&state=FINISHED,FAILED,CANCELED", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

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
		"Body={\"projectId\":7571,\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
		LAST);

	web_custom_request("previewReport", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"projectId\":7571,\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}],\"chartProfileList\":[],\"tableProfileList\":[]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}]}],\"testFilterExpressionList\":[{\""
		"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\","
		"\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\""
		"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\""
		"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
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
		"Body={\"projectId\":7571,\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\""
		":[9145,9144]}]}", 
		LAST);

	lr_think_time(4);

	web_custom_request("slaReportProfile_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"name\":\"trend_4567688\",\"projectId\":7571,\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":8,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\""
		"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}],\"orderInReport\":0}],\"tableProfileList\":[{\"tableId\":null,\"slaTypeList\":[{\"fromDate\":8,\""
		"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":53,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"},{\"fromDate\":6,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":46,\"type\":\"GENERAL_SLA_TYPE\"},{\"fromDate\":4,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":54,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"random_test\"},{\"fromDate\":13"
		",\"restrictionType\":\"AVERAGE\",\"targetType\":\"TRANSACTION\",\"toDate\":51,\"type\":\"TRANSACTION_SLA_TYPE\",\"transactionName\":\"random_transaction_666\"},{\"fromDate\":10,\"restrictionType\":\"ERROR_RATE\",\"targetType\":\"TEST\",\"toDate\":53,\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\",\"orderInReport\":1}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":[9145,9144]}]}", 
		LAST);

	lr_end_transaction("1_transactionñîçäàíèå òðåíäà",LR_AUTO);

	return 0;
}