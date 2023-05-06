function Decoder(bytes, port) {
  // Decode an uplink message from a buffer
  // (array) of bytes to an object of fields.
  var decoded = {};

  if (port === 1) {
    var tempC = ((bytes[0] << 8) | bytes[1]) / 100.0;
    decoded.temperature = tempC.toFixed(2);

    // Extract the mapped LDR value from the payload
    var ldr = bytes[2];
    decoded.ldr = ldr;
  }

  return decoded;
}
