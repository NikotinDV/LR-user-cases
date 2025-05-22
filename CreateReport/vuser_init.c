int randNum;
char reportName[20];
char randText[16];

vuser_init()
{
        srand(time(NULL));

        randNum = rand() % 10000;
        sprintf(reportName, "Nik%d", randNum);
        randNum = rand() % 10000;
        sprintf(randText, "report %d", randNum);

        lr_save_string(reportName, "reportName");
        lr_save_string(randText, "randText");
        return 0;
}
