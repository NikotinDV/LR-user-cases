char fullUrl[512];
char randomEmail[50];
char randomName[30];
int randNum;
vuser_init()
{
        srand(time(NULL));
        randNum = rand() % 10000;
        sprintf(randomEmail, "Nik%d@example.com", randNum);
        sprintf(randomName, "Nik%d", randNum);
        lr_save_string(randomEmail, "randomEmail");
        lr_save_string(randomName, "randomName");
        return 0;
}