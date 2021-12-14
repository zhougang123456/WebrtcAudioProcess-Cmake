#include "webrtc_audio_process.h"
#include <stdio.h>
int main() {
   
    if (init_audio_process(1, 0, 1, 1, 3, 1) == -1) {
        printf("apm create failed!\n");
        return -1;
    }

    const int sample_rate = 48000;
    const int channels = 2;
 
    FILE* input = fopen("noise.pcm", "rb");
    FILE* outfile = fopen("denoise.pcm", "wb");
    const int kSamples = 480 * 2;
    short input_samples[960];
    int ret;
    while (1) {
        while (!feof(input)) {
            int read = fread(input_samples, sizeof(short), kSamples, input);
            if (read == kSamples) {
                ret = audio_process_stream(sample_rate, channels, NULL, input_samples, 0);
                if (ret < 0) {
                    printf("audio_process_stream failed!\n");
                    break;
                }
                fwrite(input_samples, sizeof(short), kSamples, outfile);
            }
            else {
                break;
            }
        }
        fseek(input, 0, SEEK_SET);
    }
    
    
    return 0;
}