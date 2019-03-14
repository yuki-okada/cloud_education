#ifndef __COMMON_H__
#define __COMMON_H__

typedef signed char Sint8;
typedef unsigned char Uint8;
typedef signed short int Sint16;
typedef unsigned short int Uint16;
typedef signed long int Sint32;
typedef unsigned long int Uint32;
typedef Uint8 bool;







/*カテゴリ*/
typedef enum category { 
	English,
	Math,
	Science,
	Society 
}category;


/*ノートのデータを格納する変数(構造体)*/
typedef struct note {
	/*ユニークなIDで、他のものと区別可能*/
	Uint32 index;
	/*カテゴリ情報*/
	category subject;
	/*ノートへのポインタ*/
	char* text;
} note;




#endif // __COMMON_H__