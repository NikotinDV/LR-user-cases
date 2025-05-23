Action()
{
        lr_start_transaction("GLOBAL");
        lr_start_transaction("UC_01_TR_01_openPage");

        web_set_sockets_option("SSL_VERSION", "AUTO");

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

        lr_end_transaction("UC_01_TR_01_openPage", LR_AUTO);
        lr_start_transaction("UC_01_TR_02_loginAdmin");

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
                        "Name=username", "Value={User}", ENDITEM,
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

        web_add_header("Content-Type", "application/json");
        web_custom_request("user_2",
                           "URL=https://dev-boomq.pflb.ru/auth-srv/user",
                           "Method=PUT",
                           "TargetFrame=",
                           "Resource=0",
                           "RecContentType=application/json",
                           "Referer=https://dev-boomq.pflb.ru/account/new-test",
                           "Snapshot=t37.inf",
                           "Mode=HTML",
                           "Body={\"email\":\"nagruzka3_gr01@mail.com\",\"id\":5881,\"language\":\"EN\",\"notificationEnabled\":false}",
                           LAST);

        web_url("25",
                "URL=https://dev-boomq.pflb.ru/auth-srv/team/22",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/new-test",
                "Snapshot=t38.inf",
                "Mode=HTML",
                LAST);

        web_cleanup_cookies();

        lr_end_transaction("UC_01_TR_02_loginAdmin", LR_AUTO);

        lr_start_transaction("UC_01_TR_03_openTeam");

        web_url("team_2",
                "URL=https://dev-boomq.pflb.ru/auth-srv/team?page=0&size=11",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/teams",
                "Snapshot=t39.inf",
                "Mode=HTML",
                LAST);

        lr_end_transaction("UC_01_TR_03_openTeam", LR_AUTO);

        lr_start_transaction("UC_01_TR_04_editTeam");

        web_url("22_2",
                "URL=https://dev-boomq.pflb.ru/auth-srv/team/22",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/teams/22",
                "Snapshot=t40.inf",
                "Mode=HTML",
                LAST);

        web_add_header("Cookie", lr_eval_string("boomq_auth={teamContextCookie}; boomq_auth={authTokenCookie}"));
        web_add_auto_header("Authorization", lr_eval_string("Bearer {teamContextCookie}"));
        web_url("teamMember",
                "URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22&page=0&size=12",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/teams/25",
                "Snapshot=t41.inf",
                "Mode=HTML",
                LAST);

        lr_end_transaction("UC_01_TR_04_editTeam", LR_AUTO);

        lr_start_transaction("UC_01_TR_05_addUser");

        web_add_header("Cookie", lr_eval_string("boomq_auth={teamContextCookie}; boomq_auth={authTokenCookie}"));

        web_reg_save_param_json(
            "ParamName=inviteUrl",
            "QueryString=$..inviteUrl",
            SEARCH_FILTERS,
            LAST);

        web_custom_request("teamMember_2",
                           "URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22",
                           "Method=POST",
                           "TargetFrame=",
                           "Resource=0",
                           "RecContentType=application/json",
                           "Referer=https://dev-boomq.pflb.ru/account/teams/22",
                           "Snapshot=t42.inf",
                           "Mode=HTML",
                           "EncType=application/json",
                           "Body=[{\"email\":\"{randomEmail}\",\"permissionList\":[\"RUN\",\"EDIT\",\"VIEW\"],\"userDisplayName\":\"{randomName}\"}]",
                           LAST);

        web_url("teamMember_3",
                "URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22&page=0&size=12",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/teams/22",
                "Snapshot=t43.inf",
                "Mode=HTML",
                LAST);

        sprintf(fullUrl, "https://dev-boomq.pflb.ru%s", lr_eval_string("{inviteUrl}"));
        lr_save_string(fullUrl, "fullUrl");

        lr_end_transaction("UC_01_TR_05_addUser", LR_AUTO);

        lr_start_transaction("UC_01_TR_06_logout");
        web_cleanup_auto_headers();
        web_cleanup_cookies();

        lr_end_transaction("UC_01_TR_06_logout", LR_AUTO);
        lr_start_transaction("UC_01_TR_07_openLink");

        web_reg_save_param(
            "authTokenCookie",
            "LB=set-cookie: boomq_auth=",
            "RB=;",
            "Search=Headers",
            LAST);

        web_url("invite_request",
                "URL={fullUrl}",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=text/html",
                "Referer=",
                "Snapshot=t45.inf",
                "Mode=HTML",
                EXTRARES,
                "Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM,
                "Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", "Referer=https://dev-boomq.pflb.ru/change-password", ENDITEM,
                "Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", "Referer=https://dev-boomq.pflb.ru/change-password", ENDITEM,
                "Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM,
                "Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM,
                "Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM,
                LAST);

        web_add_auto_header("Authorization", lr_eval_string("Bearer {authTokenCookie}"));

        web_url("modelSchema",
                "URL=https://dev-boomq.pflb.ru/project-srv/modelSchema",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/change-password",
                "Snapshot=t59.inf",
                "Mode=HTML",
                LAST);

        web_url("config.json",
                "URL=https://dev-boomq.pflb.ru/config.json",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/change-password",
                "Snapshot=t60.inf",
                "Mode=HTML",
                EXTRARES,
                "Url=/static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM,
                LAST);

        lr_end_transaction("UC_01_TR_07_openLink", LR_AUTO);
        lr_start_transaction("UC_01_TR_08_enterPassword");

        web_add_header("Content-Type", "application/json");
        web_custom_request("user",
                           "URL=https://dev-boomq.pflb.ru/auth-srv/user",
                           "Method=PUT",
                           "TargetFrame=",
                           "Resource=0",
                           "RecContentType=application/json",
                           "Referer=https://dev-boomq.pflb.ru/change-password",
                           "Snapshot=t61.inf",
                           "Mode=HTML",
                           "Body={\"password\":\"Wsx321!@#\"}",
                           LAST);

        web_url("team",
                "URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/new-test",
                "Snapshot=t62.inf",
                "Mode=HTML",
                LAST);

        web_url("teamContext",
                "URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/new-test",
                "Snapshot=t63.inf",
                "Mode=HTML",
                LAST);

        web_url("testRunner",
                "URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc",
                "TargetFrame=",
                "Resource=0",
                "RecContentType=application/json",
                "Referer=https://dev-boomq.pflb.ru/account/new-test",
                "Snapshot=t64.inf",
                "Mode=HTML",
                LAST);

        lr_end_transaction("UC_01_TR_08_enterPassword", LR_AUTO);
        lr_end_transaction("GLOBAL", LR_AUTO);

        return 0;
}