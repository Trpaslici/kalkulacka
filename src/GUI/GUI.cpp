#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include "MaafLajbrry.h"
#include <ctype.h>

#define PLUS 1
#define MINUS 2
#define TIMES 3
#define DIVIDE 4
#define POWER 5
#define ROOT 6
#define COMBINATORY 7
#define EQUAL 8

#define CALC_EPSILON	0.0000000001

//vypisuje cisla do labelu
void write_in_label(const char* str1);

//odesle informace do funkce ke spocitani
void do_calculations();

void	on_button_dot_clicked(GtkButton *b);
void	on_button_zero_clicked(GtkButton *b);
void	on_button_eq_clicked(GtkButton *b);
void	on_button_one_clicked(GtkButton *b);
void	on_button_two_clicked(GtkButton *b);
void	on_button_three_clicked(GtkButton *b);
void	on_button_four_clicked(GtkButton *b);
void	on_button_five_clicked(GtkButton *b);
void	on_button_six_clicked(GtkButton *b);
void	on_button_seven_clicked(GtkButton *b);
void	on_button_eight_clicked(GtkButton *b);
void	on_button_nine_clicked(GtkButton *b);
void	on_button_div_clicked(GtkButton *b);
void	on_button_times_clicked(GtkButton *b);
void	on_button_minus_clicked(GtkButton *b);
void	on_button_plus_clicked(GtkButton *b);
void	on_button_fact_clicked(GtkButton *b);
void	on_button_pwr_clicked(GtkButton *b);
void	on_button_root_clicked(GtkButton *b);
void	on_button_comb_clicked(GtkButton *b);
void	on_button_AC_clicked(GtkButton *b);
void	on_button_sign_clicked(GtkButton *b);
void	on_button_help_clicked(GtkButton *b);


double num1;
double num2;
int oper = 0;
int eq_pressed = 0;
int output_written = 0;

GtkWidget	*window1;
GtkWidget	*fixed1;
GtkWidget	*fixed2;
GtkWidget	*button_dot;
GtkWidget	*button_zero;
GtkWidget	*button_eq;
GtkWidget	*button_one;
GtkWidget	*button_two;
GtkWidget	*button_three;
GtkWidget	*button_four;
GtkWidget	*button_five;
GtkWidget	*button_six;
GtkWidget	*button_seven;
GtkWidget	*button_eight;
GtkWidget	*button_nine;
GtkWidget	*button_div;
GtkWidget	*button_times;
GtkWidget	*button_minus;
GtkWidget	*button_plus;
GtkWidget	*button_fact;
GtkWidget	*button_pwr;
GtkWidget	*button_root;
GtkWidget	*button_comb;
GtkWidget	*button_AC;
GtkWidget	*button_sign;
GtkWidget	*button_help;
GtkWidget	*label1;
GtkBuilder	*builder;

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk
	
	GdkColor color;
	color.red = 0xcccc;
	color.green = 0xcccc;
	color.blue = 0xd900;

	builder = gtk_builder_new_from_file("GUI.glade");

	window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));

	g_signal_connect(window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// Callbacks
	gtk_builder_add_callback_symbol(builder, "on_button_dot_clicked", G_CALLBACK(on_button_dot_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_zero_clicked", G_CALLBACK(on_button_zero_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_eq_clicked", G_CALLBACK(on_button_eq_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_one_clicked", G_CALLBACK(on_button_one_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_two_clicked", G_CALLBACK(on_button_two_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_three_clicked", G_CALLBACK(on_button_three_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_four_clicked", G_CALLBACK(on_button_four_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_five_clicked", G_CALLBACK(on_button_five_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_six_clicked", G_CALLBACK(on_button_six_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_seven_clicked", G_CALLBACK(on_button_seven_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_eight_clicked", G_CALLBACK(on_button_eight_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_nine_clicked", G_CALLBACK(on_button_nine_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_div_clicked", G_CALLBACK(on_button_div_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_times_clicked", G_CALLBACK(on_button_times_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_minus_clicked", G_CALLBACK(on_button_minus_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_plus_clicked", G_CALLBACK(on_button_plus_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_fact_clicked", G_CALLBACK(on_button_fact_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_pwr_clicked", G_CALLBACK(on_button_pwr_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_root_clicked", G_CALLBACK(on_button_root_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_comb_clicked", G_CALLBACK(on_button_comb_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_AC_clicked", G_CALLBACK(on_button_AC_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_sign_clicked", G_CALLBACK(on_button_sign_clicked));
	gtk_builder_add_callback_symbol(builder, "on_button_help_clicked", G_CALLBACK(on_button_help_clicked));

	
	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button_dot = GTK_WIDGET(gtk_builder_get_object(builder, "button_dot"));
	button_zero = GTK_WIDGET(gtk_builder_get_object(builder, "button_zero"));
	button_eq = GTK_WIDGET(gtk_builder_get_object(builder, "button_eq"));
	button_one = GTK_WIDGET(gtk_builder_get_object(builder, "button_one"));
	button_two = GTK_WIDGET(gtk_builder_get_object(builder, "button_two"));
	button_three = GTK_WIDGET(gtk_builder_get_object(builder, "button_three"));
	button_four = GTK_WIDGET(gtk_builder_get_object(builder, "button_four"));
	button_five = GTK_WIDGET(gtk_builder_get_object(builder, "button_five"));
	button_six = GTK_WIDGET(gtk_builder_get_object(builder, "button_six"));
	button_seven = GTK_WIDGET(gtk_builder_get_object(builder, "button_seven"));
	button_eight = GTK_WIDGET(gtk_builder_get_object(builder, "button_eight"));
	button_nine = GTK_WIDGET(gtk_builder_get_object(builder, "button_nine"));
	button_div = GTK_WIDGET(gtk_builder_get_object(builder, "button_div"));
	button_times = GTK_WIDGET(gtk_builder_get_object(builder, "button_times"));
	button_minus = GTK_WIDGET(gtk_builder_get_object(builder, "button_minus"));
	button_plus = GTK_WIDGET(gtk_builder_get_object(builder, "button_plus"));
	button_fact = GTK_WIDGET(gtk_builder_get_object(builder, "button_pwr"));
	button_pwr = GTK_WIDGET(gtk_builder_get_object(builder, "button_fact"));
	button_root = GTK_WIDGET(gtk_builder_get_object(builder, "button_root"));
	button_comb = GTK_WIDGET(gtk_builder_get_object(builder, "button_comb"));
	button_AC = GTK_WIDGET(gtk_builder_get_object(builder, "button_AC"));
	button_sign = GTK_WIDGET(gtk_builder_get_object(builder, "button_sign"));
	button_help = GTK_WIDGET(gtk_builder_get_object(builder, "button_help"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
	
	//gtk_widget_override_background_color(GTK_WIDGET(window1), GTK_STATE_FLAG_NORMAL, &color);

	gtk_builder_connect_signals(builder, NULL);

	gtk_widget_show(window1);

	gtk_main();

	return EXIT_SUCCESS;
}

void check_and_delete()
{
	if (oper == EQUAL || output_written == 1)
	{
		gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "0");
		output_written = 0;
	}
}

void fill_first_or_second()
{
	if (oper == 0 || oper == EQUAL) {
		num1 = strtod(gtk_label_get_text(GTK_LABEL(label1)), nullptr);
		gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "0");
	}
	else {
		num2 = strtod(gtk_label_get_text(GTK_LABEL(label1)), nullptr);
		gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "0");
		do_calculations();
	}

}

//stisknuti tlacitka .
void	on_button_dot_clicked(GtkButton *b) {
	write_in_label(".");
}
//stisknuti tlacitka 0
void	on_button_zero_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("0");
}
//stisknuti tlacitka =
void	on_button_eq_clicked(GtkButton *b) {
	eq_pressed = 1;
	num2 = strtod(gtk_label_get_text(GTK_LABEL(label1)), nullptr);
	gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "0");
	do_calculations();
}
//stisknuti tlacitka 1
void	on_button_one_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("1");
}
//stisknuti tlacitka 2
void	on_button_two_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("2");
}
//stisknuti tlacitka 3
void	on_button_three_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("3");
}
//stisknuti tlacitka 4
void	on_button_four_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("4");
}

//stisknuti tlacitka 5
void	on_button_five_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("5");
}

//stisknuti tlacitka 6
void	on_button_six_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("6");
}

//stisknuti tlacitka 7
void	on_button_seven_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("7");
}

//stisknuti tlacitka 8
void	on_button_eight_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("8");
}

//stisknuti tlacitka 9
void	on_button_nine_clicked(GtkButton *b) {
	check_and_delete();
	write_in_label("9");
}

//stisknuti tlacitka deleno
void	on_button_div_clicked(GtkButton *b) {
	fill_first_or_second();
	oper = DIVIDE;
}

//stisknuti tlacitka krat
void	on_button_times_clicked(GtkButton *b) {
	fill_first_or_second();
	oper = TIMES;
}

//stisknuti tlacitka minus
void	on_button_minus_clicked(GtkButton *b) {
	fill_first_or_second();
	oper = MINUS;
}

//stisknuti tlacitka plus
void	on_button_plus_clicked(GtkButton *b) {
	fill_first_or_second();
	oper = PLUS;
}

//stisknuti tlacitka faktorial
void	on_button_fact_clicked(GtkButton *b) {
	MaafLajbrry lajbrry;
	num1 = strtod(gtk_label_get_text(GTK_LABEL(label1)), nullptr);
	num2 = lajbrry.factorial(num1);
	oper = EQUAL;
	gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "0");
	do_calculations();
}

//stisknuti tlacitka mocniny
void	on_button_pwr_clicked(GtkButton *b) {
	fill_first_or_second();
	oper = POWER;
}

//stisknuti tlacitka odmocniny
void	on_button_root_clicked(GtkButton *b) {
	fill_first_or_second();
	oper = ROOT;
}

//stisknuti tlacitka komb. cisla
void	on_button_comb_clicked(GtkButton *b) {
	fill_first_or_second();
	oper = COMBINATORY;
}

//stisknuti tlacitka AC
void	on_button_AC_clicked(GtkButton *b) {
	num1 = 0;
	num2 = 0;
	oper = 0;
	gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "0");
}

//stisknuti tlacitka +/-
void	on_button_sign_clicked(GtkButton *b) {
	num1 = strtod(gtk_label_get_text(GTK_LABEL(label1)), nullptr);
	num2 = -num1;
	oper = EQUAL;
	gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "0");
	do_calculations();
}

//stisknuti tlacitka help
void	on_button_help_clicked(GtkButton *b) {
	
}

//vypisuje cisla do labelu
void write_in_label(const char* str1) {
	const gchar* str2 = gtk_label_get_text(GTK_LABEL(label1));
	double tmpNum = strtod(gtk_label_get_text(GTK_LABEL(label1)), nullptr);
	if (tmpNum == 0) {
		gtk_label_set_text(GTK_LABEL(label1), (const gchar*)str1);
	}
	else {
		//char * pNew = (char *) malloc(sizeof(str2));
		char * pNew = new char[strlen(str2) + strlen(str1) + 1];

		pNew[0] = '\0';
		strcat(pNew, str2);
		strcat(pNew, str1);
		gtk_label_set_text(GTK_LABEL(label1), (const gchar*)pNew);
		delete[] pNew;
	}
}

void do_calculations() {
	double result;
	MaafLajbrry lajbrry;
	switch (oper) {
	case (PLUS):
		result = lajbrry.add(num1, num2);
		break;
	case (MINUS):
		result = lajbrry.sub(num1, num2);
		break;
	case (TIMES):
		result = lajbrry.mul(num1, num2);
		break;
	case (DIVIDE):
		result = lajbrry.divid(num1, num2);
		break;
	case (POWER):
		result = lajbrry.pow(num1, num2);
		break;
	case (ROOT):
		result = lajbrry.rad(num1, num2);
		break;
	case (COMBINATORY):
		result = lajbrry.komb(num1, num2);
		break;
	default:
		result = num2;
		break;
	}

	//oper = 0;
	num1 = result;
	num2 = 0;

	char tmp[50];
	if (fabs(result - (int) result) < CALC_EPSILON)
		snprintf(tmp, 50, "%d", (long) result);
	else
		snprintf(tmp, 50, "%f", result);
	write_in_label((const gchar*)tmp);				//TODO
	output_written = 1;

	if (eq_pressed == 1)
	{
		oper = EQUAL;
	}
}
