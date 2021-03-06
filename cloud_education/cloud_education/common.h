#ifndef __COMMON_H__
#define __COMMON_H__



/*int型はビット長が機種依存であるため、それらを使わない型を事前に作っておく*/
typedef signed char Sint8;
typedef unsigned char Uint8;
typedef signed short int Sint16;
typedef unsigned short int Uint16;
typedef signed long int Sint32;
typedef unsigned long int Uint32;
typedef Uint8 bool;


/*カテゴリの種類を値で判断する*/
typedef enum _category { 
	English,
	Math,
	Science,
	Society,
	National_language
}category;


/*ノートに記載されるデータを作成した構造体*/
typedef struct note {
	/*ノートのIDのようなもの(index)*/
	Uint32 index;
	/*どのカテゴリに属するか(カテゴリ情報)*/
	category subject;
	/*ノートへのポインタ(ノートに記載されているテキスト)*/
	char* text;
	/*画像のファイル名へのポインタ(ノートに張り付けられている画像ファイル)*/
	char* image;
} note;

#define NOTE_ARRAY_NUM 10


#endif // __COMMON_H__