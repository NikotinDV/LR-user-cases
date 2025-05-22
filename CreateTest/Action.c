Action()
{

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
		"Url=/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", ENDITEM, 
		"Url=/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", ENDITEM, 
		"Url=/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

	lr_think_time(5);

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=user9431@example.com", ENDITEM, 
		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
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

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=25", 
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
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("user_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"Body={\"email\":\"user9431@example.com\",\"id\":6054,\"language\":\"EN\",\"notificationEnabled\":false}", 
		LAST);

	web_url("25", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/25", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("start");

	lr_end_transaction("start",LR_AUTO);

	lr_start_transaction("add_test");

	lr_end_transaction("add_test",LR_AUTO);

	lr_start_transaction("save");

	web_custom_request("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"comment\":\"\",\"contentFormat\":\"yaml\",\"contentModelVersion\":\"2.0.0\",\"labelSet\":[],\"requestCount\":1,\"testType\":\"STABLE\",\"projectName\":\"test9431\",\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"0c3ce26d-3d36-4d16-89ef-434d7b28b24e\",\"label\":\"group9431\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\"typeDisplayName\":\"\",\"threadGroupElements\":[{\""
		"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"GET\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"/WebTours/\",\"port\":\"\",\"protocol\":\"https\",\"search\":\"?\",\"serverName\":\"webtours.pflb.ru\",\"headers\":{},\"queryParameters\":[],\"body\":\"\",\"bodyParameters\":[]},\"timerList\":[],\"label\":\"https://"
		"webtours.pflb.ru/WebTours/\",\"id\":\"f298c146-0080-4684-bbd7-f491e11e624e\",\"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"testik\",\"id\":\"7c4deef7-f107-49e3-bc3f-4266985fcc16\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\""
		"Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"c14ff465-23c4-467d-bcc8-b039e5c1ebe9\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\""
		"Http header manager\",\"id\":\"93939085-9a96-4e02-9ade-87bc4472073f\",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"d72e5239-3b32-4f47-b076-0aafc31948e6\",\"connectTimeout\":60000,\"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":1,\"rampDownMs\":0,\"durationAddedOnLastStepMs\":0,\"boomqProfileType\":\"STABLE\",\"rampUpMs\":0,\"stepLengthMs\":60000,\"stepCount\":1},\"timers\":[{\""
		"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_37ce2127-7976-426b-8c14-bbeb52b6e248\",\"id\":\"37ce2127-7976-426b-8c14-bbeb52b6e248\",\"durationMs\":8000,\"enabled\":true}]},\"slaGroupList\":[{\"type\":\"GENERAL_TEST_SLA\",\"targetType\":\"TEST\",\"slaList\":[{\"fromDate\":2,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":\"22\",\"value\":\"123123\"},{\"fromDate\":5,\"restrictionType\":\"ERROR_RATE\",\"operation\":\"LESS_EQUALS\",\"status\":\""
		"NOT_COUNTED\",\"toDate\":\"45\",\"value\":\"22\"}]},{\"type\":\"TRANSACTION_SLA\",\"targetType\":\"TRANSACTION\",\"transactionId\":\"7c4deef7-f107-49e3-bc3f-4266985fcc16\",\"transactionName\":\"testik\",\"slaList\":[{\"fromDate\":5,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":60,\"value\":\"2222\"},{\"fromDate\":34,\"restrictionType\":\"AVERAGE\",\"operation\":\"LESS_EQUALS\",\"status\":\"NOT_COUNTED\",\"toDate\":\"55\",\"value\":\"34\"}],\""
		"threadGroupId\":null,\"threadGroupName\":null}],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":60}", 
		EXTRARES, 
		"Url=../static/media/check.9725c0396328bae9471b624111fc14ca.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	lr_end_transaction("save",LR_AUTO);

	return 0;
}