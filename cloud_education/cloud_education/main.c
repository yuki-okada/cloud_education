#include <gtk/gtk.h>
#include"common.h"
#include"file_manager.h"
#include"note_manager.h"


/*メイン関数*/
static void cb_button_clicked(GtkWidget* button, gpointer user_data)
{
	gtk_main_quit();
}


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
	gtk_widget_set_size_request(window, 400, 600);
	{
		GtkWidget* vbox;

		vbox = gtk_vbox_new(FALSE, 2);

		gtk_container_add(GTK_CONTAINER(window), vbox);
		{
			GtkWidget* textview;
			GtkWidget* image;
			GtkWidget* button;

			note sample;
			bool result;

			result = read_note(0, &sample);

			image = gtk_image_new_from_file(sample.image);

			textview = gtk_text_view_new();

			

			gtk_text_buffer_set_text(gtk_text_view_get_buffer(textview), sample.text,-1);

			gtk_box_pack_start(GTK_BOX(vbox), textview, TRUE, TRUE, 0);

			gtk_box_pack_start(GTK_BOX(vbox), image, TRUE, TRUE, 0);


			button = gtk_button_new_with_label("Quit");

			gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

			g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(cb_button_clicked), NULL);
		}
	}
	/*ウィンドウの表示*/
	gtk_widget_show_all(window);
	/*メインループ*/
	gtk_main();

	file_manager_exit();
	note_manager_exit();

	return 0;
}