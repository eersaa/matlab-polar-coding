% PENCODE_CORE_CODEGEN   Generate static library pencode_core from pencode_core.
% 
% Script generated from project 'pencode_core.prj' on 18-Oct-2024.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
cfg = coder.config('lib','ecoder',true);

cfg.DataTypeReplacement = 'CBuiltIn';
cfg.GenerateReport = true;
cfg.InstructionSetExtensions = "None";
cfg.PassStructByReference = true;
cfg.ReportPotentialDifferences = true;
cfg.SaturateOnIntegerOverflow = false;
cfg.TargetLang = 'C++';

%% Define argument types for entry-point 'pencode_core'.
ARGS = cell(1,1);
ARGS{1} = coder.typeof(0,[128  1]);

%% Invoke MATLAB Coder.
codegen pencode_core -args ARGS{1} -test 'polar_code_tests'; % MEX function for testing
codegen -config cfg pencode_core -args ARGS{1} -package 'pencode_core'; % C/C++ code generation

