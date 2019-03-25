#include<stdio.h>
#include<gtk/gtk.h>
#include"common.h"
#include<stdlib.h>
#include<string.h>

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
	FILE* p_sample_file = NULL;
	Uint8 buffer[1024 * 10];
	Uint8 count = 0;
	
	/*セーブデータを読み込み*/
	if (fopen_s(&p_sample_file, "save_file.txt", "r") != 0) {
		exit(1);
	}
	else {
		/* ファイルの終端まで文字を読み取る */
		while (count = fgets(&buffer[count], sizeof(buffer), p_sample_file) != NULL) {
			printf("%s", buffer);
		}
		fclose(p_sample_file);
	}
	
	_note->index = 0;
	_note->subject = English;
	_note->text = "test";
	_note->image = "sample.png";

	return TRUE;
}