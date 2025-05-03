//#define _CRT_SECURE_NO_WARNINGS // Define this to potentially suppress other related warnings if needed,
//// though checking the fopen_s return value is the primary fix here.
//// Alternatively, you can set this in your project properties.
//
//#include <stdio.h>  // For FILE, fopen_s, fclose, fseek, ftell, rewind, fread, perror
//#include <stdlib.h> // For malloc, free, EXIT_FAILURE
//#include <string.h> // For strerror (useful with errno_t)
//
//// Function to read the entire content of a file into a dynamically allocated string.
//// Uses fopen_s for compatibility with some IDEs (like Visual Studio).
//// Returns a char* containing the file content on success, or NULL on failure.
//// The caller is responsible for freeing the returned memory.
//char* read_file_to_string_secure(const char* filename) {
//    FILE* file = NULL;
//    char* buffer = NULL;
//    long file_size = 0;
//
//    fopen_s(&file, filename, "rb");
//
//    fseek(file, 0, SEEK_END);
//    file_size = ftell(file);
//
//    rewind(file);
//
//    buffer = (char*)malloc(file_size + 1);
//    fread(buffer, 1, file_size, file);
//    buffer[file_size] = '\0';
//    fclose(file);
//
//    return buffer;
//}
//
//// Example Usage:
////int main() {
//    const char* filename = "my_document.txt"; // Replace with your file name
//    char* file_content = read_file_to_string_secure(filename); // Use the new function
//
//    if (file_content != NULL) {
//        printf("Successfully read file '%s'. Content:\n", filename);
//        printf("--------------------\n");
//        printf("%s\n", file_content);
//        printf("--------------------\n");
//
//        free(file_content);
//        printf("Memory freed.\n");
//
//    }
//    else {
//        fprintf(stderr, "Failed to read file '%s'.\n", filename);
//        return EXIT_FAILURE;
//    }
//
//    return 0;
////}
////int main() {
////	char initWord[] = "hello word";
////	char* manyWords[] = { initWord, initWord, initWord };
////
////	for (int i = 0; i < 3; i++) {
////		printf(manyWords[i]);
////		printf("\n");
////	}
////	printf("Hello world");
////	return 0;
////}