#include "framework.h"
#include "configs.h"


bool configs::bReadConfigFile(char* filename)
{
  /*  FILE* pFile;
    HANDLE hFile;
    DWORD  dwFileSize;
    char* cp, * token, cTxt[120];
    char cReadMode;
    char seps[] = "= ,\t\n";
    int	iIPindex = 0;

    hFile = CreateFileA(filename, GENERIC_READ, NULL, NULL, OPEN_EXISTING, NULL, NULL);
    dwFileSize = GetFileSize(hFile, NULL);
    if (hFile != INVALID_HANDLE_VALUE) CloseHandle(hFile);


    pFile = fopen(filename, "rt");
    if (pFile == NULL) {

        DisplayInLogList("(ERROR) Cannot open configuration file.");
        return FALSE;
    }
    else {
        DisplayInLogList("(*) Reading configuration file...");
        cp = new char[dwFileSize + 1];
        ZeroMemory(cp, dwFileSize + 1);
        fread(cp, dwFileSize, 1, pFile);

        token = strtok(cp, seps);
        while (token != NULL) {

            if (cReadMode != ConfigFileReadMode::Undefined) {
                switch (cReadMode) {
                case ConfigFileReadMode::Address:
                    ZeroMemory(IpAddress, sizeof(IpAddress));
                    strcpy(IpAddress, token);
                    wsprintf(cTxt, "(*) Server Ip Address : %s", IpAddress);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::ClientPort:
                    G_pClientSock->port = atoi(token);
                    wsprintf(cTxt, "(*) Client Port : %d", G_pClientSock->port);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::MapPort:
                    G_pMapSock->port = atoi(token);
                    wsprintf(cTxt, "(*) Map Server Port : %d", G_pMapSock->port);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::Version:
                    ZeroMemory(Version, sizeof(Version));
                    strcpy(Version, token);
                    wsprintf(cTxt, "(*) Server Version : %s", Version);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::ServerList:
                    ZeroMemory(ServerList, sizeof(ServerList));
                    strcpy(ServerList, token);
                    wsprintf(cTxt, "(*) Server List Name : %s", ServerList);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::MysqlDatabaseName:
                    ZeroMemory(MysqlDatabaseName, sizeof(MysqlDatabaseName));
                    strcpy(MysqlDatabaseName, token);
                    wsprintf(cTxt, "(*)  Mysql Database Name : %s", MysqlDatabaseName);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::MysqlUserName:
                    ZeroMemory(MysqlUserName, sizeof(MysqlUserName));
                    strcpy(MysqlUserName, token);
                    wsprintf(cTxt, "(*)  Mysql User Name : %s", MysqlUserName);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::MysqlPassword:
                    ZeroMemory(MysqlPassword, sizeof(MysqlPassword));
                    strcpy(MysqlPassword, token);
                    wsprintf(cTxt, "(*)  Mysql Password : %s", MysqlPassword);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                case ConfigFileReadMode::MysqlPort:
                    MysqlPort = atoi(token);
                    wsprintf(cTxt, "(*) Mysql port : %d", MysqlPort);
                    DisplayInLogList(cTxt);
                    cReadMode = ConfigFileReadMode::Undefined;
                    break;
                }

            }
            else {
                if (memcmp(token, "address", 7) == 0)     cReadMode = ConfigFileReadMode::Address;
                if (memcmp(token, "client-port", 11) == 0) cReadMode = ConfigFileReadMode::ClientPort;
                if (memcmp(token, "map-port", 8) == 0) cReadMode = ConfigFileReadMode::MapPort;
                if (memcmp(token, "version", 7) == 0) cReadMode = ConfigFileReadMode::Version;
                if (memcmp(token, "server-list", 11) == 0) cReadMode = ConfigFileReadMode::ServerList;
                if (memcmp(token, "mysql-database-name", 19) == 0) cReadMode = ConfigFileReadMode::MysqlDatabaseName;
                if (memcmp(token, "mysql-user-name", 15) == 0) cReadMode = ConfigFileReadMode::MysqlUserName;
                if (memcmp(token, "mysql-password", 14) == 0) cReadMode = ConfigFileReadMode::MysqlPassword;
                if (memcmp(token, "mysql-port", 10) == 0) cReadMode = ConfigFileReadMode::MysqlPort;
            }
            token = strtok(NULL, seps);
        }

        delete cp;
    }
    if (pFile != NULL) fclose(pFile);
    DisplayInLogList("(*) Reading configuration file successful");
    DisplayInLogList("");*/
    return TRUE;

}