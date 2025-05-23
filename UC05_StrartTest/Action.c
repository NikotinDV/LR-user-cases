Action()
{
        lr_start_transaction("GLOBAL");
	lr_start_transaction("UC01_T01_Login");

        web_set_sockets_option("SSL_VERSION", "AUTO");
        web_add_auto_header("Accept-Language", "ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3");
        web_set_max_html_param_len("4096");

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

        web_reg_save_param_json("ParamName=teamId", "QueryString=$..id", SEARCH_FILTERS, "Scope=Body", LAST);

        web_url("team",
                "URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2",
                "Referer=https://dev-boomq.pflb.ru/account/new-test",
                "Resource=0",
                "RecContentType=application/json",
                "Mode=HTML",
                LAST);

        web_reg_save_param("teamContextCookie", "LB=set-cookie: boomq_auth=", "RB=\r\n", "Search=Headers", LAST);

        web_url("teamContext",
                "URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}",
                "Referer=https://dev-boomq.pflb.ru/account/new-test",
                "Resource=0",
                "RecContentType=application/json",
                "Mode=HTML",
                LAST);

        web_add_auto_header("Authorization", "Bearer {teamContextCookie}");

        lr_end_transaction("UC01_T01_Login", LR_AUTO);

        lr_start_transaction("UC01_T02_searchTest");

        web_reg_save_param_json("ParamName=projectId", "QueryString=$..projectId", "SelectAll=Yes", SEARCH_FILTERS, "Scope=Body", LAST);

        web_url("project",
                "URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=1000",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/tests",
                "Snapshot=t16.inf",
                "Mode=HTML",
                LAST);

        lr_save_string(lr_paramarr_random("projectId"), "randomProjectId");

        lr_end_transaction("UC01_T02_searchTest", LR_AUTO);

        lr_start_transaction("UC01_T03_runTest");

        web_reg_save_param_json("ParamName=projectVersionId", "QueryString=$..version..id", SEARCH_FILTERS, "Scope=Body", LAST);

        web_url("projectId",
                "URL=https://dev-boomq.pflb.ru/project-srv/project/{randomProjectId}",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/tests/{randomProjectId}",
                "Snapshot=t17.inf",
                "Mode=HTML",
                LAST);

        web_url("projectVersionId",
                "URL=https://dev-boomq.pflb.ru/project-srv/project/{randomProjectId}/version/{projectVersionId}",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/tests/{randomProjectId}",
                "Snapshot=t18.inf",
                "Mode=HTML",
                LAST);

        web_custom_request("test",
                           "URL=https://dev-boomq.pflb.ru/test-srv/test",
                           "Method=POST",
                           "TargetFrame=",
                           "Resource=0",
                           "RecContentType=application/json",
                           "Referer=https://dev-boomq.pflb.ru/account/tests/{randomProjectId}",
                           "Snapshot=t20.inf",
                           "Mode=HTML",
                           "EncType=application/json",
                           "Body={\"comment\":\"\",\"labelSet\":[],\"projectId\":\"{randomProjectId}\",\"projectVersionId\":{projectVersionId},\"testMode\":\"TEST\",\"testProjectId\":\"{randomProjectId}\",\"testProjectVersionId\":{projectVersionId}}",
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

        lr_end_transaction("UC01_T03_runTest", LR_AUTO);
        lr_end_transaction("GLOBAL", LR_AUTO);

        return 0;
}