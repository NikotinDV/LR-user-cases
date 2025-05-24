char trendName[64];
char threadGroupName[64];
int i;
int numberOfElements = 0;
int count;
char paramName[64];
char testList[128];

vuser_init()
{
	int trendNum = rand() % 9999;

	sprintf(trendName, "Nik trend %d", trendNum);
	sprintf(threadGroupName, "Nik tread %d", threadGroupName);
	lr_save_string(trendName, "trendName");
	lr_save_string(threadGroupName, "threadGroupName");
	return 0;
}
