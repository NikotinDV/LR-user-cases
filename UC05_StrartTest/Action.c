Action()
{

    char teamUrl[256];

    lr_start_transaction("UC01_T01_Login");

    web_set_sockets_option("SSL_VERSION", "AUTO");
    web_add_auto_header("Accept-Language", "ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3");
    web_set_max_html_param_len("4096");

    lr_think_time(5);

    // Получаем токен при логине
    web_reg_save_param("authTokenCookie", "LB=set-cookie: boomq_auth=", "RB=;", "Search=Headers", LAST);

    web_submit_data("login",
        "Action=https://dev-boomq.pflb.ru/auth-srv/login",
        "Method=POST",
        "EncType=multipart/form-data",
        "Referer=https://dev-boomq.pflb.ru/authorize",
        "Mode=HTML",
        ITEMDATA,
        "Name=username", "Value={login}", ENDITEM,
        "Name=password", "Value={password}", ENDITEM,
        "Name=submit", "Value=Login", ENDITEM,
        LAST);

    web_add_auto_header("Authorization", "Bearer {authTokenCookie}");

    // Получаем teamId
    web_reg_save_param_json("ParamName=teamId", "QueryString=$..id", SEARCH_FILTERS, "Scope=Body", LAST);

    web_url("team",
        "URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2",
        "Referer=https://dev-boomq.pflb.ru/account/new-test",
        "Resource=0",
        "RecContentType=application/json",
        "Mode=HTML",
        LAST);

    // Получаем новый токен для teamContext
    web_reg_save_param("teamContextCookie", "LB=set-cookie: boomq_auth=", "RB=\r\n", "Search=Headers", LAST);

    lr_save_string(lr_eval_string("https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}"), "teamContextUrl");

    web_url("teamContext",
        "URL={teamContextUrl}",
        "Referer=https://dev-boomq.pflb.ru/account/new-test",
        "Resource=0",
        "RecContentType=application/json",
        "Mode=HTML",
        LAST);

    // Обновляем Authorization и Cookie
    web_add_auto_header("Authorization", "Bearer {teamContextCookie}");
    web_add_header("Cookie", "boomq_auth={teamContextCookie}; boomq_auth={authTokenCookie}");

    lr_end_transaction("UC01_T01_Login", LR_AUTO);

	lr_start_transaction("Search_Test");

	web_url("label", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Search_Test",LR_AUTO);

	lr_start_transaction("Run_TEst");

	web_url("7566", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/7566", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7566", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("8647", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/7566/version/8647", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7566", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("downloadLink", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/7566/version/8647/downloadLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7566", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/minio/boomq/boomq/teams/25/projects/7566/v_8647.yaml?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIOSFODNN7EXAMPLE/20250521/us-east-1/s3/aws4_request&X-Amz-Date=20250521T124141Z&X-Amz-Expires=604800&X-Amz-SignedHeaders=host&X-Amz-Signature=fb75c88636381b1ed849b9c0e7bbd6853982375ff8b3fb09daf579a41711c938", "Referer=https://dev-boomq.pflb.ru/account/tests/7566", ENDITEM, 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7566", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"labelSet\":[],\"projectId\":\"7566\",\"projectVersionId\":8647,\"testMode\":\"TEST\",\"testProjectId\":\"7566\",\"testProjectVersionId\":8647}", 
		LAST);

	web_url("project_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	web_url("label_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=INITIALIZATION,WAITING,RUNNING,TEST_STOPPING", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Run_TEst",LR_AUTO);

	lr_think_time(60);

	web_url("test_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=INITIALIZATION,WAITING,RUNNING,TEST_STOPPING", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_5", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(8);

	return 0;
}