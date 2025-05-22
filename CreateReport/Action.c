Action()
{
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

        web_set_max_html_param_len("4096");

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
                "URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/new-test",
                "Snapshot=t8.inf",
                "Mode=HTML",
                LAST);

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

        web_add_header("Cookie", lr_eval_string("boomq_auth={teamContextCookie}; boomq_auth={authTokenCookie}"));
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
                           "Body={\"labelSet\":[],\"name\":\"{reportName}\",\"testIdSet\":[],\"reportContent\":{\"charts\":[],\"reportMarkup\":\"[{\\\"id\\\":\\\"PNnfFYQfvw\\\",\\\"type\\\":\\\"paragraph\\\",\\\"data\\\":{\\\"text\\\":\\\"{randText}\\\"}},{\\\"id\\\":\\\"S2MhdvkUIR\\\",\\\"type\\\":\\\"list\\\",\\\"data\\\":{\\\"style\\\":\\\"unordered\\\",\\\"items\\\":[\\\"{randText}\\\",\\\"{randText}\\\",\\\"{randText}\\\"]}},{\\\"id\\\":\\\"5a6HxBfkCq\\\",\\\"type\\\":\\\"table\\\",\\\"data\\\":{\\\"withHeadings\\\":false,\\\"content\\\":[[\\\"{randText}\\\",\\\"{randText}\\\",\\\"{randText}\\\"],[\\\"{randText}\\\",\\\"{randText}\\\",\\\"{randText}\\\"]]}}]\",\"tables\":[]}}",
                           LAST);

        web_url("report",
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

        lr_end_transaction("1_report", LR_AUTO);

        return 0;
}