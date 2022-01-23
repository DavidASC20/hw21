#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  while(1){
    from_client = server_handshake( &to_client );
    char line[1000];
    char reverse[1000];
    while(read(from_client, line, sizeof(line)) != 0){
      int i = 0;
      for (i = strlen(line) - 1; i >= 0; i--){
			if (*(line + i) != 10){
				strncat(reverse, line + i, 1);
			}
		}
      write(to_client, reverse, sizeof(line));
    }
  }
}