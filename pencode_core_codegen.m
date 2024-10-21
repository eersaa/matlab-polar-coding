% PENCODE_CORE_CODEGEN   Generate static library pencode_core from pencode_core.
% 
% Script generated from project 'pencode_core.prj' on 18-Oct-2024.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
cfg = coder.config('lib','ecoder',true);

cfg.CompileTimeRecursionLimit = 0;
cfg.DataTypeReplacement = 'CBuiltIn';
cfg.EnableDynamicMemoryAllocation = false;
cfg.EnableMemcpy = false;
cfg.EnableRuntimeRecursion = false;
cfg.EnableSignedLeftShifts = true;
cfg.EnableSignedRightShifts = true;
cfg.EnableVariableSizing = false;
cfg.GenerateReport = true;
cfg.InstructionSetExtensions = "None";
cfg.MaxIdLength = 1024;
cfg.PassStructByReference = true;
cfg.PurelyIntegerCode = true;
cfg.ReportPotentialDifferences = false;
cfg.SaturateOnIntegerOverflow = false;
cfg.TargetLang = 'C++';

%% Define argument types for entry-point 'pencode_core'.
ARGS = cell(1,1);
ARGS{1} = coder.typeof(false,[128  1]);

%% Invoke MATLAB Coder.
codegen -config cfg pencode_core -args ARGS{1}

