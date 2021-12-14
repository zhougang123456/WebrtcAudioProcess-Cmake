#include "webrtc_audio_process.h"
#include "modules/audio_processing/audio_processing_impl.h"

using namespace webrtc;
static  rtc::scoped_refptr<AudioProcessing> apm = nullptr;
int init_audio_process(int use_aec, int use_aecm, int use_hpf, int use_ans, int ns_level, int use_agc) {

    if (apm != nullptr) {
        return 0;
    }

    apm = AudioProcessingBuilder().Create();
    if (apm == nullptr) {
        return -1;
    }

    AudioProcessing::Config config;
    config.echo_canceller.enabled = use_aec;
    config.echo_canceller.mobile_mode = use_aecm;

    config.gain_controller1.enabled = use_agc;
    config.gain_controller1.mode =
        AudioProcessing::Config::GainController1::kAdaptiveAnalog;

    config.gain_controller2.enabled = use_agc;

    config.high_pass_filter.enabled = use_hpf;

    config.voice_detection.enabled = true;

    config.transient_suppression.enabled = true;
    config.noise_suppression.enabled = use_ans;
    config.noise_suppression.level = (AudioProcessing::Config::NoiseSuppression::Level)ns_level;

    apm->ApplyConfig(config);

    return 0;
}

int audio_process_stream(int sample_rate, int channels, short* far_samples, short* near_samples, int delay)
{   
    int ret = 0;
    const StreamConfig input_config(sample_rate, channels);
    const StreamConfig ouput_config(sample_rate, channels);

    if (far_samples) {
        ret = apm->ProcessReverseStream(far_samples, input_config, ouput_config, far_samples);
        if (ret != 0) {
            return -1;
        }
        apm->set_stream_delay_ms(delay);
    }
    ret = apm->ProcessStream(near_samples, input_config, ouput_config, near_samples);

    return ret;
}
