use std::fs::File;

use std::i16;
use std::f64::consts::PI;
use std::thread::sleep;
use std::time::Duration;

use ::openal::{self, al, alc};

use ::vorbis::Decoder;

pub fn play(file_ogg: &'static str) {
  // initialising OpenAL
  let device: openal::alc::Device = alc::Device::open(None).expect("Could not open device");

  let ctx = device.create_context(&[]).expect("Could not create context");
  ctx.make_current();

  // create the required objects to play the soundtrack
  let buffer = al::Buffer::gen();
  let source = al::Source::gen();

  // load PCM data from the file
  let vorbis_decoder = Decoder::new(File::open(file_ogg).unwrap()).unwrap();
  let mut pcm_buffer = Vec::new();

  for packet in vorbis_decoder.into_packets().map(Result::unwrap) {
    pcm_buffer.extend(packet.data);
  }

  let sample_freq = 44100.0;
  let tone_freq = 440.0;
  let duration = 10.0;
  let num_samples = (sample_freq * duration) as usize;

  let _: Vec<i16> = (0..num_samples).map(|x| {
    let t = x as f64;
    ((tone_freq * t * 2.0 * PI / sample_freq).sin() * (i16::MAX - 1) as f64) as i16
  }).collect();

  // fill the OpenAL buffers with the PCM data
  unsafe { buffer.buffer_data(al::Format::Mono16, &pcm_buffer, 44100) };

  source.queue_buffer(&buffer);
  source.play();

  sleep(Duration::from_millis((duration * 1000.0) as u64));

  ctx.destroy();
  device.close().ok().expect("Unable to close device");
}
