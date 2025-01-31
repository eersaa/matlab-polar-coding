rng(100);
N_block_length = 128;
K_message_length = 64;
Ec_BPSK_symbol_energy = 1;
N0_noise = 2;
global PCparams;
initPC(N_block_length, ...
        K_message_length, ...
        Ec_BPSK_symbol_energy, ...
        N0_noise)

message = (rand(K_message_length,1)>0.5);
ref_encoded_message = logical(pencode(message));

message_with_frozen_bits = PCparams.FZlookup;
message_with_frozen_bits(PCparams.FZlookup == -1) = message;

encoded_message = logical(pencode_core(logical(message_with_frozen_bits)));

assert(isequal(encoded_message, ref_encoded_message))
