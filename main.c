#include <stdio.h>

// Máscaras de permissões para cada bit de leitura, escrita e execução
#define USER_READ  0x100 // Permissão de leitura para o proprietário
#define USER_WRITE 0x080  // Permissão de escrita para o proprietário
#define USER_EXEC  0x040  // Permissão de execução para o proprietário
#define GROUP_READ 0x020  // Permissão de leitura para o grupo
#define GROUP_WRITE 0x010 // Permissão de escrita para o grupo
#define GROUP_EXEC 0x008  // Permissão de execução para o grupo
#define OTHER_READ 0x004  // Permissão de leitura para outros
#define OTHER_WRITE 0x002 // Permissão de escrita para outros
#define OTHER_EXEC 0x001  // Permissão de execução para outros

// Função para solicitar e validar a entrada do usuário
int get_permissions() {
    int octal_permission;
    printf("Digite as permissões em formato octal (ex: 764): ");
    scanf("%o", &octal_permission);

    // Validação: verificar se está entre 000 e 777
    if (octal_permission < 0 || octal_permission > 0777) {
        printf("Permissões inválidas. Insira um valor entre 000 e 777.\n");
        return -1;
    }
    return octal_permission;
}

// Função para exibir as permissões em formato -rwxrwxrwx
void print_permission_bits(int permissions, const char *filename) {
    printf("-");
    
    // Imprimir permissões do proprietário
    printf("%c", (permissions & USER_READ) ? 'r' : '-');
    printf("%c", (permissions & USER_WRITE) ? 'w' : '-');
    printf("%c", (permissions & USER_EXEC) ? 'x' : '-');

    // Imprimir permissões do grupo
    printf("%c", (permissions & GROUP_READ) ? 'r' : '-');
    printf("%c", (permissions & GROUP_WRITE) ? 'w' : '-');
    printf("%c", (permissions & GROUP_EXEC) ? 'x' : '-');

    // Imprimir permissões de outros
    printf("%c", (permissions & OTHER_READ) ? 'r' : '-');
    printf("%c", (permissions & OTHER_WRITE) ? 'w' : '-');
    printf("%c", (permissions & OTHER_EXEC) ? 'x' : '-');

    printf(" %s\n", filename);
}

int main() {
    const char filename[] = "arquivo.txt";

    // Obter permissões do usuário
    int permissions = get_permissions();
    if (permissions == -1) {
        return 1;  // Finaliza o programa caso a entrada seja inválida
    }

    // Imprime as permissões formatadas
    print_permission_bits(permissions, filename);

    return 0;
}
