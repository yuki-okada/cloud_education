#include<stdio.h>
#include"common.h"

void note_manager_init()
{
	printf("ノートマネージャー初期化完了\n");
}

void note_manager_exit()
{
	printf("ノートマネージャー終了\n");
}

/*ノートの設定ファイルを読み込む関数*/
note read_note(Uint32 index)
{
	/*ノートのXMLを解析して各メンバに与える*/

}