////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_random_letters(char *buffer, int length) {
    const char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int i;

    for (i = 0; i < length - 1; i++) {
        buffer[i] = letters[rand() % 26];
    }

    buffer[length - 1] = '\0';  // null-terminator
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Action()
{
    char reportName[20];
    char randText[16];
    char randItem1[16];
    char randItem2[16];
    char randItem3[16];
    char randCell1[16];
    char randCell2[16];
    char randCell3[16];
    char Row2Col1[16];
    char Row2Col2[16];
    char Row2Col3[16];
    int randNum;

    srand((unsigned int)time(NULL));

    randNum = rand() % 10000;
    sprintf(reportName, "%d", randNum); // Только номер

    generate_random_letters(randText, sizeof(randText));
    generate_random_letters(randItem1, sizeof(randItem1));
    generate_random_letters(randItem2, sizeof(randItem2));
    generate_random_letters(randItem3, sizeof(randItem3));
    generate_random_letters(randCell1, sizeof(randCell1));
    generate_random_letters(randCell2, sizeof(randCell2));
    generate_random_letters(randCell3, sizeof(randCell3));
    generate_random_letters(Row2Col1, sizeof(Row2Col1));
    generate_random_letters(Row2Col2, sizeof(Row2Col2));
    generate_random_letters(Row2Col3, sizeof(Row2Col3));

    lr_save_string(reportName, "reportName");
    lr_save_string(randText, "randText");
    lr_save_string(randItem1, "randItem1");
    lr_save_string(randItem2, "randItem2");
    lr_save_string(randItem3, "randItem3");
    lr_save_string(randCell1, "randCell1");
    lr_save_string(randCell2, "randCell2");
    lr_save_string(randCell3, "randCell3");
    lr_save_string(Row2Col1, "Row2Col1");
    lr_save_string(Row2Col2, "Row2Col2");
    lr_save_string(Row2Col3, "Row2Col3");

web_add_auto_header("Accept-Language", 
		"ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3");

	web_url("authorize", 
		"URL=https://dev-boomq.pflb.ru/authorize", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	lr_think_time(5);
	
web_set_max_html_param_len("4096");	
	
web_reg_save_param(
    "authToken",
    "LB=authorization:",
    "RB=\r\n",
    "Search=Headers",
    LAST);
    
    web_reg_save_param(
    "authTokenCookie",
    "LB=set-cookie: boomq_auth=",
    "RB=;",
    "Search=Headers",
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
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);
	
	lr_output_message("Authorization token = %s", lr_eval_string("{authTokenCookie}"));
	
	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Authorization", lr_eval_string("Bearer {authTokenCookie}"));
	
	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);
	
	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	
	
	 web_reg_save_param(
    		"teamContextCookie",
    		"LB=set-cookie: boomq_auth=",
   		 "RB=\r\n",
    		"Search=Headers",
   		 LAST);
	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=25", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	lr_output_message("Authorization token = %s", lr_eval_string("{teamContextCookie}"));
	
	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	

	lr_start_transaction("1_report");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(4);
	
 web_add_header("Cookie",  lr_eval_string("boomq_auth={teamContextCookie}; boomq_auth={authTokenCookie}"));
 web_add_auto_header("Authorization", lr_eval_string("Bearer {teamContextCookie}"));
 
	web_custom_request("search", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"pagination\":{\"pageNumber\":0,\"pageSize\":9},\"sort\":[{\"field\":\"CREATED_AT\",\"direction\":\"DESC\"}]}", 
		LAST);

	lr_think_time(7);

	web_url("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=FINISHED", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/new", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(51);
	
web_reg_save_param_json(
    "ParamName=reportId",        
    "QueryString=$.id",         
    "SelectAll=No",
    LAST);

	web_custom_request("report", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/new", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		//"Body={\"labelSet\":[],\"name\":\"Report_22222\",\"testIdSet\":[],\"reportContent\":{\"charts\":[],\"reportMarkup\":\"[{\\\"id\\\":\\\"PNnfFYQfvw\\\",\\\"type\\\":\\\"paragraph\\\",\\\"data\\\":{\\\"text\\\":\\\"asdasdasdasdasd\\\"}},{\\\"id\\\":\\\"S2MhdvkUIR\\\",\\\"type\\\":\\\"list\\\",\\\"data\\\":{\\\"style\\\":\\\"unordered\\\",\\\"items\\\":[\\\"asdasdasdasd\\\",\\\"asdasdasdasd\\\",\\\"asdasdasdasd\\\"]}},{\\\"id\\\":\\\"5a6HxBfkCq\\\",\\\"type\\\":\\\"table\\\",\\\"data\\\":{\\\""
		//"withHeadings\\\":false,\\\"content\\\":[[\\\"asdsadasdasdasdasd\\\",\\\"asdasdasdasd\\\",\\\"asdasdasdasd\\\"],[\\\"asdasdasdasdasdasd\\\",\\\"asdasdsadasd\\\",\\\"asdasdasdasd\\\"]]}}]\",\"tables\":[]}}", 
		//LAST);
  		"Body={\"labelSet\":[],\"name\":\"Report_{reportName}\",\"testIdSet\":[],\"reportContent\":{\"charts\":[],\"reportMarkup\":\"[{\\\"id\\\":\\\"PNnfFYQfvw\\\",\\\"type\\\":\\\"paragraph\\\",\\\"data\\\":{\\\"text\\\":\\\"{randText}\\\"}},{\\\"id\\\":\\\"S2MhdvkUIR\\\",\\\"type\\\":\\\"list\\\",\\\"data\\\":{\\\"style\\\":\\\"unordered\\\",\\\"items\\\":[\\\"{randItem1}\\\",\\\"{randItem2}\\\",\\\"{randItem3}\\\"]}},{\\\"id\\\":\\\"5a6HxBfkCq\\\",\\\"type\\\":\\\"table\\\",\\\"data\\\":{\\\"withHeadings\\\":false,\\\"content\\\":[[\\\"{randCell1}\\\",\\\"{randCell2}\\\",\\\"{randCell3}\\\"],[\\\"{Row2Col1}\\\",\\\"{Row2Col2}\\\",\\\"{Row2Col3}\\\"]]}}]\",\"tables\":[]}}",
  		LAST);

	web_url("5851", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/{reportId}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/{reportId}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("content", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/{reportId}/content", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/{reportId}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=FINISHED", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/{reportId}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_report",LR_AUTO);

	return 0;
}