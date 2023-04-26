#include "mips.h"
#include <unistd.h>
#include <fcntl.h>

/**
 * @brief Função principal do programa.
 *
 * @return 0 se a execução for bem-sucedida.
 */
int main(int argc, char *const argv[])
{
	int fp;
	int size = 10;
	int buffer[10];

	if (argc != 0)
	{
	}

	fp = open(argv[1], O_RDONLY);

	if (fp < 0)
	{
		printf("Erro ao abrir o arquivo\n");
		return 1;
	}

	if (read(fp, buffer, size) != size)
	{
		printf("Erro na leitura do arquivo\n");
		close(fp);
		return 1;
	}

	mips_load(buffer, size);
	mips_exec();

	close(fp);
	mips_clean();

	return 0;
}
