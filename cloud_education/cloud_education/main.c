#include <gtk/gtk.h>
#include"common.h"
#include"file_manager.h"
#include"note_manager.h"
#include"data_server.h"


/*67行目で呼び出された関数が行う処理*/
static void cb_button_clicked(GtkWidget* button, gpointer user_data)
{
	/*gtk_mainのループを終えてね*/
	gtk_main_quit();
}


int main(int argc, char** argv[])
{
	/*メインウィンドウを宣言*/
	GtkWidget* main_window;

	file_manager_init();
	note_manager_init();
	data_server_init();
	
	

	/*GTK+の初期化及びオプション解析に必要な関数*/
	gtk_init(&argc, argv);
	/*メインウィンドウの作成*/
	main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	/*メインウィンドウの大きさの設定*/
	gtk_widget_set_size_request(main_window, 600, 800);
	{
		/*メインウィンドウ内に縦方向で複数のウィジェットを配置するボックスを宣言*/
		GtkWidget* main_window_vbox;

		/*メインウィンドウに縦方向に複数のウィジェットを配置するボックスを作成する関数*/
		main_window_vbox = gtk_vbox_new(FALSE, 2);


		/*この関数内で宣言されたウィジェットを、()内にあるウィンドウに縦方向に配置する関数*/
		gtk_container_add(GTK_CONTAINER(main_window), main_window_vbox);
		{
			GtkWidget* textview;

			/*ファイルから読み込む画像を宣言*/
			GtkWidget* sample_image;
			/*アプリケーションを終了するボタンの宣言*/
			GtkWidget* button_of_quit_aplication;

			note sample;
			bool result;

			result = read_note(0, &sample);

			/*画像ウィジェットを作成する関数*/
			sample_image = gtk_image_new_from_file(sample.image);

			textview = gtk_text_view_new();

			

			/*gtk_text_buffer_set_text(gtk_text_view_get_buffer(textview), sample.text,-1);*/

			/*テキスト画面のウィジェットをメインウィンドウのボックス内にどのように配置するか決定する関数*/
			gtk_box_pack_start(GTK_BOX(main_window_vbox), textview, TRUE, TRUE, 0);
			/*サンプル画像のウィジェットをメインウィンドウのボックス内にどのように配置するか決定する関数*/
			gtk_box_pack_start(GTK_BOX(main_window_vbox), sample_image, TRUE, TRUE, 0);


			/*アプリケーションの終了を実行するボタンを作成する関数*/
			button_of_quit_aplication = gtk_button_new_with_label("Quit");
			/*アプリ終了のボタンウィジェットをメインウィンドウのボックス内にどのように配置するか決定する関数*/
			gtk_box_pack_start(GTK_BOX(main_window_vbox), button_of_quit_aplication, FALSE, FALSE, 0);

			/*button_of_quit_aplicationがクリックされたときに呼び出す関数(行ってほしい操作)を結び付ける関数*/
			g_signal_connect(G_OBJECT(button_of_quit_aplication), "clicked", G_CALLBACK(cb_button_clicked), NULL);
		}
	}

	/*メインウィンドウ内にあるウィジェットをすべて表示する関数*/
	gtk_widget_show_all(main_window);
	
	/*メインループ*/
	gtk_main();

	file_manager_exit();
	note_manager_exit();
	data_server_exit();

	return 0;
}