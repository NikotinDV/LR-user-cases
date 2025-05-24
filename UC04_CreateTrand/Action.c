Action()
{
	lr_start_transaction("GLOBAL");

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

	lr_start_transaction("UC04_TR01_signIn");

	web_add_header("Origin", "https://dev-boomq.pflb.ru");

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

	web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token}"));

	web_add_cookie("boomq_auth={auth_token}; DOMAIN=dev-boomq.pflb.ru");

	web_reg_save_param_json(
		"ParamName=teamId",
		"QueryString=$..id",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);

	web_url("team",
			"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=application/json",
			"Referer=https://dev-boomq.pflb.ru/account/new-test",
			"Snapshot=t3.inf",
			"Mode=HTML",
			LAST);

	web_url("user",
			"URL=https://dev-boomq.pflb.ru/auth-srv/user",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=application/json",
			"Referer=https://dev-boomq.pflb.ru/account/new-test",
			"Snapshot=t4.inf",
			"Mode=HTML",
			LAST);

	web_reg_save_param("auth_token_new",
					   "LB=set-cookie: boomq_auth=",
					   "RB=\r\n",
					   "Search=Headers",
					   LAST);

	web_url("team_context",
			"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId={teamId}",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=application/json",
			"Referer=https://dev-boomq.pflb.ru/account/new-test",
			"Snapshot=t5.inf",
			"Mode=HTML",
			LAST);

	web_add_header("Cookie", lr_eval_string("boomq_auth={auth_token_new}; boomq_auth={auth_token}"));

	web_add_auto_header("Authorization", lr_eval_string("Bearer {auth_token_new}"));

	lr_end_transaction("UC04_TR01_signIn", LR_AUTO);
	lr_start_transaction("UC04_TR02_openTrand");

	web_url("slaReportProfile",
			"URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=application/json",
			"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles",
			"Snapshot=t6.inf",
			"Mode=HTML",
			LAST);

	lr_end_transaction("UC04_TR02_openTrand", LR_AUTO);
	lr_start_transaction("UC04_TR03_addNewTrand");

	web_reg_save_param_json(
		"ParamName=projectId",
		"QueryString=$.content[*].id",
		"SelectAll=Yes",
		LAST);

	web_url("project",
			"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=application/json",
			"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
			"Snapshot=t7.inf",
			"Mode=HTML",
			LAST);

	lr_end_transaction("UC04_TR03_addNewTrand", LR_AUTO);
	lr_start_transaction("UC04_TR04_selectTest");

	count = atoi(lr_eval_string("{projectId_count}"));

	for (i = 1; i <= count; i++)
	{

		sprintf(paramName, "{projectId_%d}", i);
		lr_save_string(lr_eval_string(paramName), "currentProjectId");

		web_reg_save_param_json(
			"ParamName=numberOfElements",
			"QueryString=$.numberOfElements",
			LAST);

		web_reg_save_param_json(
			"ParamName=testId",
			"QueryString=$.content[*].testResult.testId",
			"SelectAll=Yes",
			"NotFound=warning",
			LAST);

		web_url("test",
				"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&size=999999&projectId={currentProjectId}&state=FINISHED,FAILED,CANCELED",
				"TargetFrame=",
				"Resource=0",
				"RecContentType=application/json",
				"Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
				"Snapshot=t8.inf",
				"Mode=HTML",
				LAST);

		numberOfElements = atoi(lr_eval_string("{numberOfElements}"));
		if (numberOfElements > 1)
		{
			sprintf(testList, "[%s,%s]", lr_eval_string("{testId_1}"), lr_eval_string("{testId_2}"));
			lr_save_string(testList, "testIdList");
			break;
		}
	}

	lr_end_transaction("UC04_TR04_selectTest", LR_AUTO);
	lr_start_transaction("UC04_TR05_next");

	web_custom_request("slaTypeList",
					   "URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/slaTypeList",
					   "Method=POST",
					   "TargetFrame=",
					   "Resource=0",
					   "RecContentType=application/json",
					   "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
					   "Snapshot=t9.inf",
					   "Mode=HTML",
					   "EncType=application/json",
					   "Body={\"projectId\":{currentProjectId},\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":{testIdList}}]}",
					   LAST);

	web_custom_request("previewReport",
					   "URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport",
					   "Method=POST",
					   "TargetFrame=",
					   "Resource=0",
					   "RecContentType=application/json",
					   "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
					   "Snapshot=t10.inf",
					   "Mode=HTML",
					   "EncType=application/json",
					   "Body={\"projectId\":{currentProjectId},\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":{testIdList}}],\"chartProfileList\":[],\"tableProfileList\":[]}",
					   LAST);

	lr_end_transaction("UC04_TR05_next", LR_AUTO);
	lr_start_transaction("UC04_TR06_addItems");

	web_custom_request("previewReport_2",
					   "URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport",
					   "Method=POST",
					   "TargetFrame=",
					   "Resource=0",
					   "RecContentType=application/json",
					   "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
					   "Snapshot=t11.inf",
					   "Mode=HTML",
					   "EncType=application/json",
					   "Body={\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":60,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"{threadGroupName}\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":{testIdList}}]}",
					   LAST);

	web_custom_request("previewReport_3",
					   "URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport",
					   "Method=POST",
					   "TargetFrame=",
					   "Resource=0",
					   "RecContentType=application/json",
					   "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
					   "Snapshot=t12.inf",
					   "Mode=HTML",
					   "EncType=application/json",
					   "Body={\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":60,\"type\":\"GENERAL_SLA_TYPE\"}]}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":{testIdList}}]}",
					   LAST);

	web_custom_request("previewReport_5",
					   "URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile/previewReport",
					   "Method=POST",
					   "TargetFrame=",
					   "Resource=0",
					   "RecContentType=application/json",
					   "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
					   "Snapshot=t13.inf",
					   "Mode=HTML",
					   "EncType=application/json",
					   "Body={\"projectId\":{currentProjectId},\"chartProfileList\":[],\"tableProfileList\":[{\"slaTypeList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":60,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"}],\"valueType\":\"VALUE\"}],\"testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":{testIdList}}]}",
					   LAST);

	lr_end_transaction("UC04_TR06_addItems", LR_AUTO);
	lr_start_transaction("UC04_TR07_save");

	web_custom_request("slaReportProfile_2",
					   "URL=https://dev-boomq.pflb.ru/test-srv/slaReportProfile",
					   "Method=POST",
					   "TargetFrame=",
					   "Resource=0",
					   "RecContentType=application/json",
					   "Referer=https://dev-boomq.pflb.ru/account/sla-report-profiles/new",
					   "Snapshot=t14.inf",
					   "Mode=HTML",
					   "EncType=application/json",
					   "Body={\"name\":\"{trendName}\",\"projectId\":{currentProjectId},\"chartProfileList\":[{\"slaTypeList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"targetType\":\"THREAD_GROUP\",\"toDate\":60,\"type\":\"THREAD_GROUP_SLA_TYPE\",\"threadGroupName\":\"{threadGroupName}\"}],\"orderInReport\":0},{\"slaTypeList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":60,\"type\":\"GENERAL_SLA_TYPE\"}],\"orderInReport\":1}],\"tableProfileList\":[{\"tableId\":null,\""
					   "slaTypeList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"targetType\":\"TEST\",\"toDate\":60,\"type\":\"GENERAL_SLA_TYPE\"}],\"valueType\":\"VALUE\",\"orderInReport\":2},{\"tableId\":null,\"slaTypeList\":[{\"fromDate\":0,\"restrictionType\":\"AVERAGE\",\"targetType\":\"REQUEST\",\"toDate\":60,\"type\":\"REQUEST_SLA_TYPE\",\"transactionFilterType\":\"ANY_TRANSACTION\",\"requestName\":\"https://webtours.pflb.ru/WebTours/\"}],\"valueType\":\"VALUE\",\"orderInReport\":3}],\""
					   "testFilterExpressionList\":[{\"type\":\"TEST_ID_EXPRESSION\",\"testIdList\":{testIdList}}]}",
					   LAST);

	lr_end_transaction("UC04_TR07_save", LR_AUTO);
	lr_end_transaction("GLOBAL", LR_AUTO);

	return 0;
}