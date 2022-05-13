/*
 * @Author: Xinke1310
 * @Date: 2022-05-13 11:24:38
 * @Last Modified by:   Xinke1310
 * @Last Modified time: 2022-05-13 11:24:38
 */
#include<iostream>
#include<string.h>
using namespace std;
int main(int argc, char** argv) {
    char** temp = argv;
    FILE* fp;
    int num = 0;
    int i = 0;
    if (strcmp(temp[1], "-c") == 0) {
        if ((fp = fopen(temp[2], "r")) == NULL) {
            cout << "文件打开失败, error" << endl;
            return 0;
        }
        while (!feof(fp)) {
            fgetc(fp) && num++;
        }
        cout << "文件中共有字符 " << num << "个" << endl;
    }
    else if (strcmp(temp[1], "-w") == 0) {
        if ((fp = fopen(temp[2], "r")) == NULL) {
            cout << "文件打开失败, error" << endl;
            return 0;
        }
        while (!feof(fp)) {
            char t = fgetc(fp);
            bool f;
            if (t >= 'a' && t <= 'z') {
                f = true;
            }
            else if (t >= 'A' && t <= 'Z') {
                f = true;
            }
            else {
                if (f == true) {
                    num++;
                }
                f = false;
            }
        }
        cout << "文件中共有单词 " << num << "个" << endl;
    }
    return 0;
}