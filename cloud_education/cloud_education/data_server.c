#include<stdio.h>
#include<gtk/gtk.h>
#include"common.h"
#include<stdlib.h>
#include<string.h>


/*ノートのxmlを解析した結果をどんどん保存する変数(構造体)*/
note note_array[NOTE_ARRAY_NUM];



void data_server_init()
{
	printf("データサーバー初期化完了\n");
}

void data_server_exit()
{
	printf("データサーバー終了\n");
}

