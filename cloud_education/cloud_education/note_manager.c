#include<stdio.h>
#include<gtk/gtk.h>
#include"common.h"

void note_manager_init()
{
	printf("ノートマネージャー初期化完了\n");
}

void note_manager_exit()
{
	printf("ノートマネージャー終了\n");
}

/*ノートのXMLを解析して各メンバに与える*/
/*ノートの設定ファイルを読み込む関数*/
bool read_note(Uint32 index, note* _note)	/*indexはノートを分別する*/
{

	
	_note->index = 0;
	_note->subject = English;
	_note->text = "test";

	return TRUE;
}