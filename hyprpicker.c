#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
      FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = popen("hyprpicker", "r");
  if (fp == NULL) {
    system("notify-send 'Hyperpicker' 'Failed to execute the program'");
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    char * bildirimTemplate = "notify-send -a 'Hyprpicker' 'Hyperpicker' 'The color code is : %s \n The code copied to clipboard' ";
   

    size_t bildirimUzunluk = strlen(bildirimTemplate) + strlen(path) + 1;
    char * bildirim = malloc(bildirimUzunluk);
    sprintf(bildirim,bildirimTemplate,path);
    system(bildirim);
    free(bildirim);

    char * kopyalaTemplate = "echo '%s' | xclip -selection clipboard";
    size_t kopyalaUzunluk = strlen(kopyalaTemplate) + strlen(path) + 1;
    char * kopyala = malloc(kopyalaUzunluk);

    sprintf(kopyala,kopyalaTemplate,path);
    system(kopyala);
    free(kopyala);
    break;
  }

  /* close */
  pclose(fp);

  return 0;
    return 0;
}


