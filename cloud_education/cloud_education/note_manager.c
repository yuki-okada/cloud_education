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

/*ノートのindex(どこにあるどのノートか)を受け取り、ノートにある情報(場所や記載されている文章など)を解析して、返す関数*/
bool read_note(Uint32 index, note* _note)	/*indexはノートを分別する*/
{

	
	_note->index = 0;
	_note->subject = English;
	_note->text = "test";
	_note->image = "sample.png";

	return TRUE;
}