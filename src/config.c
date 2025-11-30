#include <stdio.h>
#include <string.h>

char font_address[256];
int font_size =  24;
int window_width =  250;
int window_height = 250;

void load_config(void)
{
	char line[256];
	FILE * file = fopen("sticky_notes.conf", "r");

	if (!file)
	{
		puts("Could not load configeration file");
		return;
	}
	
	while ( fgets(line, 256, file) )
	{
		if (strstr(line, "font_address"))
		{
			char * font_text = strchr(line, '"');
			font_text++;
			strncpy(font_address, font_text, 256);
			for (char * c = font_address; *c != 0; c++)
			{
				if (*c == '"')
				{
					*c = 0;
				}
			}
		}
		else if ( strstr(line, "font_size") )
		{
			sscanf(line, "%*[^0-9]%d", &font_size);
		}
		else if ( strstr(line, "window_width") )
		{
			sscanf(line, "%*[^0-9]%d", &window_width);
		}
		else if ( strstr(line, "window_height") )
		{
			sscanf(line, "%*[^0-9]%d", &window_height);
		}

	}
	fclose(file);
}
