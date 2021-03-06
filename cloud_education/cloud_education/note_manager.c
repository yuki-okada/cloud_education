#include<stdio.h>
#include<gtk/gtk.h>
#include"common.h"
#include<stdlib.h>
#include<string.h>
#include<libxml/xmlreader.h>
#include"data_server.h"

/**/
typedef enum _state {
	STATE_NONE,
	STATE_INDEX,
	STATE_CATEGORY,
	STATE_TEXT,
	STATE_IMAGE
}state;


void note_manager_init()
{
	printf("ノートマネージャー初期化完了\n");
}

void note_manager_exit()
{
	printf("ノートマネージャー終了\n");
}

category change_result_of_xml_into_subject(xmlChar* value) {
	
	category result_subject = 0;

	if (value == "0") {
		result_subject = English;
	}
	else if (value == "1") {
		result_subject = Math;
	}
	else if (value == "2") {
		result_subject = Science;
	}
	else if (value == "3") {
		result_subject = Society;
	}
	else if (value == "4") {
		result_subject = National_language;
	}

	return result_subject;
}


/*今、xmlのどこを解析しているか知る関数*/
void processNode(xmlTextReaderPtr reader) {
	
	/**/
	xmlElementType nodeType;
	/**/
	xmlChar* name;
	/**/
	xmlChar* value;
	/*enum型の変数の初期化は無効値を入れておく*/
	static state status = STATE_NONE;
	/**/
	static note result;
	/**/
	category category_enum;

	//  ノード情報の取得
	nodeType = xmlTextReaderNodeType(reader);       //  ノードタイプ
	name = xmlTextReaderName(reader);               //  ノード名
	if (name == 0) {
		name = xmlStrdup(BAD_CAST "---");
	}

	if (nodeType = XML_ELEMENT_NODE) {              //  開始
		if (xmlStrcmp(name, BAD_CAST "index") == 0) {
			status = STATE_INDEX;
		}
		else if (xmlStrcmp(name, BAD_CAST "category") == 0) {
			status = STATE_CATEGORY;
		}
		else if (xmlStrcmp(name, BAD_CAST "text") == 0) {
			status = STATE_TEXT;
		}
		else if (xmlStrcmp(name, BAD_CAST "image") == 0) {
			status = STATE_IMAGE;
		}
	}
	else if (nodeType == XML_READER_TYPE_END_ELEMENT) {   //  終了
		status = STATE_NONE;
		note_array[result.index] = result;

	}
	else if (nodeType == XML_TEXT_NODE) {          //  テキスト
//  テキストを取得する
		value = xmlTextReaderValue(reader);

		if (value == 0) {
			value = xmlStrdup(BAD_CAST "---");
		}
		if (status == STATE_INDEX) {
			/*結果を入れる("文字"の数字を"数値"の数字に変換)*/
			result.index = atoi(value);
		}
		else if (status == STATE_CATEGORY) {
			category_enum = change_result_of_xml_into_subject(value);
			result.subject = category_enum;
		}
		else if (status == STATE_TEXT) {
			result.text = value;
		}
		else if (status == STATE_IMAGE) {
			result.image = value;
		}
		xmlFree(value);
	}
	xmlFree(name);
}


/*ノートのindex(どこにあるどのノートか)を受け取り、ノートにある情報(場所や記載されている文章など)を解析して、返す関数*/
bool read_note(Uint32 index, note* _note)	/*indexはノートを分別する*/
{
	bool ret = FALSE;
	
	/**/
	xmlTextReaderPtr reader;

	/**/
	reader = xmlNewTextReaderFilename("./save_file.xml");

	ret = xmlTextReaderRead(reader);
	while (ret == 1) {
		//  現在のノードを処理(processNodeは別途定義)
		processNode(reader);

		//  次のノードに移動
		ret = xmlTextReaderRead(reader);
	}

	//  Reader のすべてのリソースを開放
	xmlFreeTextReader(reader);



	_note->index = 0;
	_note->subject = English;
	_note->text = "test";
	_note->image = "sample.png";

	return TRUE;
}





/*FILE* p_sample_file = NULL;
	Uint8 buffer[1024 * 10];
	Uint8 count = 0;

	セーブデータを読み込み
	if (fopen_s(&p_sample_file, "save_file.txt", "r") != 0) {
		exit(1);
	}
	else {
		/* ファイルの終端まで文字を読み取る
		while (count = fgets(&buffer[count], sizeof(buffer), p_sample_file) != NULL) {
			printf("%s", buffer);
		}
		fclose(p_sample_file);
	}
	*/
