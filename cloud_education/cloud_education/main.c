#include <gtk/gtk.h>
#include"common.h"
#include"file_manager.h"
#include"note_manager.h"


/*メイン関数*/

int main(int argc, char** argv[])
{
	GtkWidget* window;

	file_manager_init();
	note_manager_init();

	/*GTK+の初期化及びオプション解析*/
	gtk_init(&argc, argv);
	/*ウィンドウの作成*/
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	/*ウィンドウの大きさの設定*/
	gtk_widget_set_size_request(window, 300, 200);
	/*ウィンドウの表示*/
	gtk_widget_show(window);
	/*メインループ*/
	gtk_main();

	file_manager_exit();
	note_manager_exit();

	return 0;
}