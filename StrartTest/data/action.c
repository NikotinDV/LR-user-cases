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

	web_add_header("sec-ch-ua", 
		"\"Chromium\";v=\"136\", \"Microsoft Edge\";v=\"136\", \"Not.A/Brand\";v=\"99\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	web_add_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("dev-boomq.pflb.ru", 
		"URL=https://dev-boomq.pflb.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Sec-Fetch-Storage-Access", 
		"active");

	web_url("proxy", 
		"URL=https://api.nucleusvpn.com/api/proxy", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://dev-boomq.pflb.ru/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		"Url=https://dev-boomq.pflb.ru/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("selection", 
		"URL=https://arc.msn.com/v4/api/selection?placement=88000360&nct=1&fmt=json&ADEFAB=0&OPSYS=WIN10&locale=ru&country=RU&edgeid=57328830060768469&ACHANNEL=4&ABUILD=136.0.7103.113&poptin=0&devosver=10.0.26100.4061&clr=esdk&UITHEME=dark&EPCON=0&AMAJOR=136&AMINOR=0&ABLD=7103&APATCH=113", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-AFS-CV", 
		"");

	web_add_header("X-AFS-ClientInfo", 
		"platform=Windows; os=Windows NT; osVer=10.0.26100; app=Microsoft Edge; appVer=136.0.3240.76; appChannel=stable; appInstallationId=57328830060768469; region=RU;");

	web_custom_request("GetUserKeyData.srf", 
		"URL=https://login.live.com/ppsecure/GetUserKeyData.srf", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"EncType=application/octet-stream", 
		"Body=<?xml version=\"1.0\"?>\n<s:Envelope xmlns:s=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ps=\"http://schemas.microsoft.com/Passport/SoapServices/PPCRL\" xmlns:wsse=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-secext-1.0.xsd\">\n <s:Header>\n  <wsse:Security>\n   <wsse:BinarySecurityToken ValueType=\"ps:loginprooftoken\" id=\"LoginProofToken\">M.C547_BAY.0.U.ClIGlqUr4qGo7QCV4rtKZYwd55DpqPLx4ITWSKpUYcVqxXDG2qeZqhIHDrc+"
		"9nFytoADdz9QlYYN9Utk57FxUH4ACCwnZKtj9arkjm2NBanCo2FjGXRfqbNuB87TAHcnCzubB0j3ny8uO+NjdmXIHGzpAmFmf5gW0FUBLB0zhZROTZy96ntPpvTY74+5qxi6rBiPvzURo/oorWhYC027QBOEOd1Qs0ak/1dX0TIdh/eYKPQ3FiNldzKJ+wUnw9IbUXpbL0cHtjJyP2splDZp3WV0bZPNt0FnOdknVJxetOx4FpIfEtb89ZE3al5pzEym3rOr10Al/iQRR8QVu33EFV8FnjYGu4pwaVNxlMNOwItPtoKYoE25qmr6AHAKVoeMXhRyhMNmADTZ9hafOSrXp5ymwKY+Peb813x+EZiAahkpo/rF5Q7bbYp9h3SSaEqGrJPadJDy98ugK/hAo0QWUaMfLyIWgDlcd4/SZAol2GjX+WsmAOZRKavHMPhIuvidTdWEhNh61TOjOpLNh98h20n3fhAq5kG7vXhxany7qLje</wsse"
		":BinarySecurityToken>\n  </wsse:Security>\n </s:Header>\n <s:Body>\n  <ps:GetKeyDataRequest xmlns:ps=\"http://schemas.microsoft.com/Passport/SoapServices/PPCRL\" Id=\"RSTS\" version=\"1.0\">\n   <ps:KeyPurposes>\n    <ps:KeyPurpose>AnaheimCredentialKey</ps:KeyPurpose>\n   </ps:KeyPurposes>\n  </ps:GetKeyDataRequest>\n </s:Body>\n</s:Envelope>\n", 
		LAST);

	lr_start_transaction("Login");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2025-05-21T12:40:41.604Z");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"136\", \"Microsoft Edge\";v=\"136\", \"Not.A/Brand\";v=\"99\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(15);

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=nagruzka3_gr01@mail.com", ENDITEM, 
		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=25", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("user_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"Body={\"email\":\"nagruzka3_gr01@mail.com\",\"id\":5881,\"language\":\"EN\",\"notificationEnabled\":false}", 
		LAST);

	web_url("25", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/25", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

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

	lr_start_transaction("Run_Test_2");

	web_url("label_3", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_url("project_3", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(5);

	web_url("7565", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/7565", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7565", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	web_url("8648", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/7565/version/8648", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7565", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	web_url("downloadLink_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/7565/version/8648/downloadLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7565", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/minio/boomq/boomq/teams/25/projects/7565/v_8648.yaml?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIOSFODNN7EXAMPLE/20250521/us-east-1/s3/aws4_request&X-Amz-Date=20250521T124332Z&X-Amz-Expires=604800&X-Amz-SignedHeaders=host&X-Amz-Signature=747b85e8b73553a957dcbf2380ad40c89544fde0f1ddb7585bc0b66ec4279009", "Referer=https://dev-boomq.pflb.ru/account/tests/7565", ENDITEM, 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_custom_request("test_6", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/7565", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"labelSet\":[],\"projectId\":\"7565\",\"projectVersionId\":8648,\"testMode\":\"TEST\",\"testProjectId\":\"7565\",\"testProjectVersionId\":8648}", 
		LAST);

	web_url("project_4", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	web_url("label_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user_4", 
		"URL=https://dev-boomq.pflb.ru/test-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_7", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=INITIALIZATION,WAITING,RUNNING,TEST_STOPPING", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_8", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Run_Test_2",LR_AUTO);

	return 0;
}