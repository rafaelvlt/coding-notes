#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* memsrch(void* bloco, size_t tamanho_bloco, void* sub_bloco, size_t tamanho_sub_bloco){
  
  if (tamanho_sub_bloco == 0) return bloco;
  if (tamanho_sub_bloco > tamanho_bloco) return NULL;

  char* b = bloco;
  char* sb = sub_bloco;
  for (size_t i = 0; i <= tamanho_bloco - tamanho_sub_bloco; i++){
    if (*(b + i) == *sb){
      int found = 1;
      for (size_t j = 1; j < tamanho_sub_bloco; j++){
        if (*(b + i + j) != *(sb + j)){
          found = 0;
          break;
        }
      }
      if (found) return (void*)(b+i);
    }
  }

  return NULL;
}

// Função helper para imprimir os resultados
void check(const char* title, void* result, void* expected) {
    if (result == expected) {
        printf("✅ [PASSOU] %s\n", title);
    } else {
        printf("❌ [FALHOU] %s (Esperado: %p, Recebido: %p)\n", title, expected, result);
    }
}

int main() {
    printf("--- Iniciando Testes para memsrch ---\n\n");

    // --- Testes com Strings (char*) ---
    printf("## Testes de String\n");
    char* bloco_str = "abracadabra";
    size_t tam_bloco = strlen(bloco_str); // 11 bytes

    char* sub1 = "bra";    // 3 bytes
    char* sub2 = "xyz";    // 3 bytes
    char* sub3 = "a";      // 1 byte
    char* sub4 = "dabra";  // 5 bytes
    char* sub5 = "abracadabra"; // 11 bytes
    char* sub6 = "abracadabras"; // 12 bytes
    char* sub7 = "";       // 0 bytes

    // Teste 1: Busca básica no meio
    check("Busca básica ('bra')", 
          memsrch(bloco_str, tam_bloco, sub1, strlen(sub1)), 
          (void*)(bloco_str + 1));

    // Teste 2: Busca sem correspondência
    check("Busca sem correspondência ('xyz')", 
          memsrch(bloco_str, tam_bloco, sub2, strlen(sub2)), 
          NULL);

    // Teste 3: Busca de 1 byte (testa o loop 'j' < 1)
    check("Busca de 1 byte ('a')", 
          memsrch(bloco_str, tam_bloco, sub3, strlen(sub3)), 
          (void*)(bloco_str + 0)); // Deve achar o PRIMEIRO 'a'

    // Teste 4: Busca no final
    check("Busca no final ('dabra')", 
          memsrch(bloco_str, tam_bloco, sub4, strlen(sub4)), 
          (void*)(bloco_str + 6));

    // Teste 5: Sub-bloco == Bloco
    check("Sub-bloco igual ao Bloco", 
          memsrch(bloco_str, tam_bloco, sub5, strlen(sub5)), 
          (void*)(bloco_str + 0));

    // Teste 6: Sub-bloco > Bloco
    check("Sub-bloco maior que Bloco", 
          memsrch(bloco_str, tam_bloco, sub6, strlen(sub6)), 
          NULL);

    // Teste 7: Sub-bloco de tamanho 0
    check("Sub-bloco de tamanho 0", 
          memsrch(bloco_str, tam_bloco, sub7, 0), 
          (void*)bloco_str); // Deve retornar o início do bloco

    // --- Testes com Dados Genéricos (int*) ---
    printf("\n## Testes de Dados (Inteiros)\n");
    int bloco_int[] = {10, 20, 30, 40, 50, 60};
    size_t tam_bloco_int = sizeof(bloco_int); // 6 * sizeof(int)

    int sub_int1[] = {30, 40};
    size_t tam_sub_int1 = sizeof(sub_int1); // 2 * sizeof(int)

    int sub_int2[] = {50, 60, 70}; // '70' está fora do bloco
    size_t tam_sub_int2 = sizeof(sub_int2);

    int sub_int3[] = {20, 30, 50}; // '30' e '50' não são contíguos
    size_t tam_sub_int3 = sizeof(sub_int3);

    // Teste 8: Busca de array de int
    check("Busca de array de int {30, 40}", 
          memsrch(bloco_int, tam_bloco_int, sub_int1, tam_sub_int1), 
          (void*)(&bloco_int[2]));

    // Teste 9: Busca de array de int (passa do limite)
    check("Busca de int (passa do limite)", 
          memsrch(bloco_int, tam_bloco_int, sub_int2, tam_sub_int2), 
          NULL);

    // Teste 10: Busca de int (não contíguo)
    check("Busca de int (não contíguo)", 
          memsrch(bloco_int, tam_bloco_int, sub_int3, tam_sub_int3), 
          NULL);

    printf("\n--- Testes Concluídos ---\n");
    return 0;
}
