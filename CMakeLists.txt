add_definitions(-DWEBRTC_LINUX)
add_definitions(-DWEBRTC_POSIX)
add_definitions(-DRTC_DISABLE_LOGGING)
add_definitions(-DWEBRTC_USE_BUILTIN_ISAC_FIX)
add_definitions(-DRTC_DISABLE_TRACE_EVENTS)
add_definitions(-DRTC_DISABLE_METRICS)
add_definitions(-DRTC_DISABLE_CHECK_MSG)
add_definitions(-DWEBRTC_AUDIO_PROCESSING_ONLY_BUILD)
add_definitions(-DWEBRTC_NS_FLOAT)

set (WEBRTC_PROJECT_NAME "webrtc-audio-process")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread -O2 -Wall -fPIC -fno-rtti -mfma")  #设置c++的编译选项

set (
    DIR_CLINK_WEBRTC_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc_audio_process.cc
    # absl
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/absl/base/internal/throw_delegate.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/absl/strings/ascii.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/absl/strings/match.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/absl/strings/string_view.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/absl/strings/internal/memutil.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/absl/types/bad_optional_access.cc
    # rtc_base
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/checks.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/platform_thread_types.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/race_checker.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/memory/aligned_malloc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/time_utils.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/system_time.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/string_encode.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/experiments/field_trial_parser.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/strings/string_builder.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/rtc_base/system/file_wrapper.cc
    # system_wrappers
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/system_wrappers/source/clock.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/system_wrappers/source/field_trial.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/system_wrappers/source/cpu_features.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/system_wrappers/source/metrics.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/system_wrappers/source/denormal_disabler.cc
    # api
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/api/audio/echo_canceller3_config.cc
    # third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/third_party/pffft/src/pffft.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/third_party/rnnoise/src/rnn_vad_weights.cc
    # common_audio
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/audio_util.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/audio_converter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/fir_filter_c.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/fir_filter_avx2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/fir_filter_factory.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/fir_filter_sse.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/ring_buffer.c
    # common_audio/vad
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/vad/vad.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/vad/webrtc_vad.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/vad/vad_core.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/vad/vad_filterbank.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/vad/vad_gmm.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/vad/vad_sp.c
    # common_audio/third_party
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/third_party/spl_sqrt_floor/spl_sqrt_floor.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/third_party/ooura/fft_size_128/ooura_fft_sse2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/third_party/ooura/fft_size_256/fft4g.cc
    # common_audio/resampler
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/resampler/push_resampler.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/resampler/push_sinc_resampler.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/resampler/resampler.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/resampler/sinc_resampler.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/resampler/sinc_resampler_sse.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/resampler/sinc_resampler_avx2.cc
    # common_audio/signal_processing
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/real_fft.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/copy_set_operations.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/division_operations.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/min_max_operations.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/get_scaling_square.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/vector_scaling_operations.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/randomization_functions.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/spl_sqrt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/energy.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/downsample_fast.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/complex_fft.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/complex_bit_reverse.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/resample_48khz.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/resample.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/resample_fractional.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/resample_by_2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/resample_by_2_internal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/splitting_filterC.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/dot_product_with_scale.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/spl_init.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/spl_inl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/common_audio/signal_processing/cross_correlationC.c
    # modulde/audio_processing
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/audio_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/audio_processing_impl.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/audio_processing_builder_impl.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/gain_control_impl.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/gain_controller2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/high_pass_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/level_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/optionally_built_submodule_creators.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/residual_echo_detector.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/rms_level.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/splitting_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/three_band_filter_bank.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/typing_detection.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/voice_detection.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/echo_control_mobile_impl.cc
    # modulde/audio_processing/include
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/include/audio_processing.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/include/config.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/include/aec_dump.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/include/audio_processing_statistics.cc
    # modulde/audio_processing/aec3
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter_avx2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter_erl.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter_erl_avx2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/aec_state.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/aec3_common.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/aec3_fft.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/alignment_mixer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/api_call_jitter_metrics.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/block_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/block_delay_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/block_framer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/block_processor.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/block_processor_metrics.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/clockdrift_detector.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/coarse_filter_update_gain.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/comfort_noise_generator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/decimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/dominant_nearend_detector.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/downsampled_render_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/echo_audibility.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/echo_canceller3.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/echo_path_delay_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/echo_path_variability.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/echo_remover.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/echo_remover_metrics.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/erl_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/erle_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/fft_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/fft_data_avx2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/filter_analyzer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/frame_blocker.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/fullband_erle_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/matched_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/matched_filter_avx2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/matched_filter_lag_aggregator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/moving_average.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/refined_filter_update_gain.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/render_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/render_delay_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/render_delay_controller.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/render_delay_controller_metrics.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/render_signal_analyzer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/residual_echo_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/reverb_decay_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/reverb_frequency_response.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/reverb_model.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/reverb_model_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/signal_dependent_erle_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/spectrum_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/stationarity_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/subband_erle_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/subband_nearend_detector.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/subtractor.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/subtractor_output.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/subtractor_output_analyzer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/suppression_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/suppression_gain.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/transparent_mode.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aec3/vector_math_avx2.cc
    # modulde/audio_processing/aecm
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aecm/aecm_core.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aecm/aecm_core_c.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/aecm/echo_control_mobile.cc
    # modulde/audio_processing/agc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/agc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/agc_manager_direct.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/clipping_predictor.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/clipping_predictor_evaluator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/clipping_predictor_level_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/loudness_histogram.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/utility.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/legacy/analog_agc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc/legacy/digital_agc.cc
    # modulde/audio_processing/agc2
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/auto_correlation.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/features_extraction.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/lp_residual.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/pitch_search.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/pitch_search_internal.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/rnn.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/rnn_fc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/rnn_gru.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/spectral_features.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/spectral_features_internal.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/rnn_vad/vector_math_avx2_agc2.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/adaptive_agc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/adaptive_digital_gain_applier.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/adaptive_mode_level_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/biquad_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/fixed_digital_level_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/gain_applier.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/interpolated_gain_curve.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/limiter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/limiter_db_gain_curve.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/noise_level_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/saturation_protector.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/saturation_protector_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/vad_with_level.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/vector_float_frame.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/agc2/cpu_features_agc2.cc
    # modulde/audio_processing/echo_detector
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/echo_detector/circular_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/echo_detector/mean_variance_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/echo_detector/moving_max.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/echo_detector/normalized_covariance_estimator.cc
    # modulde/audio_processing/ns
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/fast_math.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/histograms.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/noise_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/noise_suppressor.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/ns_fft.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/prior_signal_model.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/prior_signal_model_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/quantile_noise_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/signal_model.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/signal_model_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/speech_probability_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/suppression_params.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/ns/wiener_filter.cc
    # modulde/audio_processing/vad
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/gmm.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/pitch_based_vad.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/pitch_internal.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/pole_zero_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/standalone_vad.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/vad_audio_proc.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/vad_circular_buffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/vad/voice_activity_detector.cc
    # modulde/audio_processing/transient
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/transient/transient_suppressor_impl.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/transient/file_utils.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/transient/moving_moments.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/transient/transient_detector.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/transient/wpd_node.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/transient/wpd_tree.cc
    # modulde/audio_processing/utility
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/utility/cascaded_biquad_filter.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/utility/delay_estimator.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/utility/delay_estimator_wrapper.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/utility/pffft_wrapper.cc
    # modulde/audio_processing/logging
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/logging/apm_data_dumper.cc
    # modulde/audio_processing/capture_levels_adjuster
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/capture_levels_adjuster/audio_samples_scaler.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_processing/capture_levels_adjuster/capture_levels_adjuster.cc
    # modulde/audiocoding/codecs
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/filter_functions.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/isac_vad.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_estimator.c
    ${CMAKE_CURRENT_SOURCE_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_filter.c

    CACHE INTERNAL "clink werbrtc source dir"
)

add_library(${WEBRTC_PROJECT_NAME} SHARED ${DIR_CLINK_WEBRTC_SRCS})
target_include_directories(
            ${WEBRTC_PROJECT_NAME} 
            PUBLIC 
            ${CMAKE_CURRENT_SOURCE_DIR}
            ${CMAKE_CURRENT_SOURCE_DIR}/webrtc
)

target_link_libraries (${WEBRTC_PROJECT_NAME} -lstdc++)

install(TARGETS ${WEBRTC_PROJECT_NAME} DESTINATION  /usr/local/lib/)
