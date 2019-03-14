#ifndef __COMMON_H__
#define __COMMON_H__

/*機種依存のint型を防ぐためにtypedefで新たに肩を宣言する*/
typedef signed char Sint8;
typedef unsigned char Uint8;
typedef signed short int Sint16;
typedef unsigned short int Uint16;
typedef signed long int Sint32;
typedef unsigned long int Uint32;
typedef Uint8 bool;


/*カテゴリの状態を定義しておく。*/
typedef enum category { 
	English,
	Math,
	Science,
	Society 
}category;


/*ノートに関するデータ(変数)を持つ構造体を定義*/
typedef struct note {
	/*他のノートと区別できるID(index)*/
	Uint32 index;
	/*どのカテゴリに属するか(カテゴリ情報)*/
	category subject;
	/*ノートへのポインタ(ノートに記載されているテキスト)*/
	char* text;
	/*画像のファイル名へのポインタ(ノートに張り付けられている画像ファイル)*/
	char* image;
} note;




#endif // __COMMON_H__