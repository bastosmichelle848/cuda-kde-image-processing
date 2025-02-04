// kde_openmp.cpp - Implementação com OpenMP em C++

#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;

const int WIDTH = 512, HEIGHT = 512;
const double BANDWIDTH = 1.0;

double gaussian_kernel(double x, double y, double bandwidth) {
    return exp(-(x*x + y*y) / (2 * bandwidth * bandwidth)) / (2 * M_PI * bandwidth * bandwidth);
}

void calculate_kde(const unsigned char* input_image, double* output_image, double bandwidth) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            double density = 0.0;
            for (int k = 0; k < HEIGHT; k++) {
                for (int l = 0; l < WIDTH; l++) {
                    double x_diff = j - l;
                    double y_diff = i - k;
                    int idx = (k * WIDTH + l); // Calcula o índice da imagem 1D
                    density += input_image[idx] * gaussian_kernel(x_diff, y_diff, bandwidth);
                }
            }
            int out_idx = (i * WIDTH + j);
            output_image[out_idx] = density;
        }
    }
}

int main() {
    int width, height, channels;
    unsigned char* img = stbi_load("/home/alunos/tei/2024/tei24801/image.jpg", &width, &height, &channels, 1);  // Caminho correto da imagem em escala de cinza
    
    if (!img) {
        cerr << "Erro ao carregar a imagem." << endl;
        return -1;
    }

    unsigned char* img_resized = new unsigned char[WIDTH * HEIGHT];
    // Redimensionamento manual simples (poderia ser melhorado para métodos de redimensionamento mais sofisticados)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int src_idx = ((i * height) / HEIGHT) * width + (j * width) / WIDTH;
            img_resized[i * WIDTH + j] = img[src_idx];
        }
    }

    // Calcular KDE
    double* output_image = new double[WIDTH * HEIGHT];
    cout << "Calculando KDE..." << endl;
    calculate_kde(img_resized, output_image, BANDWIDTH);

    // Salvar a imagem de saída (usando o stb_image_write)
    stbi_write_png("output_kde.png", WIDTH, HEIGHT, 1, output_image, WIDTH * sizeof(double));
    cout << "Resultados salvos em 'output_kde.png'." << endl;

    // Liberar a memória
    stbi_image_free(img);
    delete[] img_resized;
    delete[] output_image;

    return 0;
}

// Definições para as bibliotecas stb_image e stb_image_write

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
