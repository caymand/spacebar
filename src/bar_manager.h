#ifndef BAR_MANAGER_H
#define BAR_MANAGER_H

struct bar_manager
{
  struct bar **bars;
  int bar_count;
  char *t_font_prop;
  char *i_font_prop;
  CTFontRef t_font;
  CTFontRef i_font;
  char **_space_icon_strip;
  char **_power_icon_strip;
  char *_cpu_icon;
  char *_mem_icon;
  char *_clock_icon;
  char *_clock_format;
  char *_space_icon;
  char *_dnd_icon;
  char *_left_shell_icon;
  char *_right_shell_icon;
  char *position;
  char *display;
  char *_display_separator_icon;
  uint32_t height;
  uint32_t padding_left;
  uint32_t padding_right;
  uint32_t spacing_left;
  uint32_t spacing_right;
  bool title;
  bool spaces;
  bool spaces_for_all_displays;
  bool display_separator;
  bool cpu;
  bool mem;
  bool clock;
  bool power;
  bool dnd;
  bool left_shell_on;
  bool right_shell_on;
  bool center_shell_on;
  char *left_shell_output;
  char *right_shell_output;
  char *center_shell_output;
  char *left_shell_command;
  char *right_shell_command;
  char *center_shell_command;
  char *cpu_output;
  char *mem_output;
  struct rgba_color foreground_color;
  struct rgba_color background_color;
  struct rgba_color space_icon_color;
  struct rgba_color space_icon_color_secondary;
  struct rgba_color space_icon_color_tertiary;
  struct rgba_color cpu_icon_color;
  struct rgba_color mem_icon_color;
  struct rgba_color battery_icon_color;
  struct rgba_color power_icon_color;
  struct rgba_color clock_icon_color;
  struct rgba_color dnd_icon_color;
  struct rgba_color left_shell_icon_color;
  struct rgba_color right_shell_icon_color;
  struct rgba_color display_separator_icon_color;
  struct rgba_color background_color_dim;
  struct bar_line *space_icon_strip;
  struct bar_line space_icon;
  struct bar_line cpu_icon; //specify the cpu field on the bar
  struct bar_line mem_icon;
  struct bar_line clock_icon;
  struct bar_line battr_icon;
  struct bar_line power_icon;
  struct bar_line dnd_icon;
  struct bar_line left_shell;
  struct bar_line left_shell_icon;
  struct bar_line right_shell;
  struct bar_line right_shell_icon;
  struct bar_line center_shell;
  struct bar_line display_separator_icon;
};

void bar_manager_set_foreground_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_background_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_space_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_space_icon_color_secondary(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_space_icon_color_tertiary(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_battery_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_power_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_clock_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_dnd_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_display_separator_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_left_shell_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_right_shell_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_text_font(struct bar_manager *bar_manager, char *font_string);
void bar_manager_set_icon_font(struct bar_manager *bar_manager, char *font_string);
void bar_manager_set_space_strip(struct bar_manager *bar_manager, char **icon_strip);
void bar_manager_set_power_strip(struct bar_manager *bar_manager, char **icon_strip);

void bar_manager_set_cpu_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_cpu(struct bar_manager *bar_manager, bool value);
void bar_manager_set_cpu_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_cpu_output(struct bar_manager *bar_manager, float cpu_load);

void bar_manager_set_mem_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_mem(struct bar_manager *bar_manager, bool value);
void bar_manager_set_mem_icon_color(struct bar_manager *bar_manager, uint32_t color);
void bar_manager_set_mem_output(struct bar_manager *bar_manager, int mem_usage);

void bar_manager_set_clock_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_clock_format(struct bar_manager *bar_manager, char *format);
void bar_manager_set_space_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_dnd(struct bar_manager *bar_manager, bool value);
void bar_manager_set_dnd_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_left_shell_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_display_separator(struct bar_manager *bar_manager, bool value);
void bar_manager_set_display_separator_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_right_shell_icon(struct bar_manager *bar_manager, char *icon);
void bar_manager_set_position(struct bar_manager *bar_manager, char *pos);
void bar_manager_set_title(struct bar_manager *bar_manager, bool value);
void bar_manager_set_spaces(struct bar_manager *bar_manager, bool value);
void bar_manager_set_spaces_for_all_displays(struct bar_manager *bar_manager, bool value);
void bar_manager_set_clock(struct bar_manager *bar_manager, bool value);
void bar_manager_set_power(struct bar_manager *bar_manager, bool value);
void bar_manager_set_height(struct bar_manager *bar_manager, uint32_t height);
void bar_manager_set_padding_left(struct bar_manager *bar_manager, uint32_t padding);
void bar_manager_set_padding_right(struct bar_manager *bar_manager, uint32_t padding);
void bar_manager_set_spacing_left(struct bar_manager *bar_manager, uint32_t spacing);
void bar_manager_set_spacing_right(struct bar_manager *bar_manager, uint32_t spacing);
void bar_manager_set_left_shell(struct bar_manager *bar_manager, bool value);
void bar_manager_set_right_shell(struct bar_manager *bar_manager, bool value);
void bar_manager_set_center_shell(struct bar_manager *bar_manager, bool value);
void bar_manager_set_left_shell_output(struct bar_manager *bar_manager, char *output);
void bar_manager_set_right_shell_output(struct bar_manager *bar_manager, char *output);
void bar_manager_set_center_shell_output(struct bar_manager *bar_manager, char *output);
void bar_manager_set_left_shell_command(struct bar_manager *bar_manager, char *command);
void bar_manager_set_right_shell_command(struct bar_manager *bar_manager, char *command);
void bar_manager_set_center_shell_command(struct bar_manager *bar_manager, char *command);
void bar_manager_set_display(struct bar_manager *bar_manager, char *display);

void bar_manager_display_changed(struct bar_manager *bar_manager);
void bar_manager_refresh(struct bar_manager *bar_manager);
void bar_manager_resize(struct bar_manager *bar_manager);
void bar_manager_begin(struct bar_manager *bar_manager);
void bar_manager_init(struct bar_manager *bar_manager);

void set_shell_outputs(struct bar_manager *bar_manager);

#endif
