#ifndef _WEBRTC_AUDIO_PROCESS_H
#define _WEBRTC_AUDIO_PROCESS_H
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    extern int init_audio_process(int use_aec, int use_aecm, int use_hpf, int use_ans, int ns_level, int use_agc);
    extern int audio_process_stream(int sample_rate, int channels, short* far_samples, short* near_samples, int delay);

#ifdef __cplusplus
};
#endif // __cplusplus
#endif // _WEBRTC_AUDIO_PROCESS_H
