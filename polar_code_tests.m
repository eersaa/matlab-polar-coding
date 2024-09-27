classdef polar_code_tests < matlab.unittest.TestCase
    properties (SetAccess = private)
        message
        ref_encoded_message
        PCparams
    end
    properties (SetAccess = public)
    end
    methods (TestClassSetup)
        function setup(self)
            close all;

            self.compute_reference_output;
            self.write_data_to_file(self.message, 'input.txt');
            self.write_data_to_file(self.ref_encoded_message, 'reference_output.txt');

        end
    end
    methods(Test)
        function should_produce_same_output_with_reference(self)
            encoded_message = self.message;
            self.verifyEqual(encoded_message, self.ref_encoded_message)
        end
    end
    methods
        function compute_reference_output(self)
            rng(100);
            N_block_length = 128;
            K_message_length = 64;
            Ec_BPSK_symbol_energy = 1;
            N0_noise = 2;

            initPC(N_block_length, ...
                    K_message_length, ...
                    Ec_BPSK_symbol_energy, ...
                    N0_noise)
            
            self.message = (rand(K_message_length,1)>0.5);
            self.ref_encoded_message = logical(pencode(self.message));
        end

        function write_data_to_file(self, data, filename)
            fileID = fopen(filename, 'w');
            fprintf(fileID, '%i\n', data);
            fclose(fileID);
        end
    end
end
