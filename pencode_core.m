function x=pencode_core(d)
x = d;

for i=1:int32(defs.stages)
    B = 2^(int32(defs.stages)-i+1);
    nB = 2^(i-1);
    for j=1:nB
        base = (j-1)*B;
        for l=1:B/int32(2)
            x(base+l) = mod( x(base+l)+x(base+B/int32(2)+l), int32(2) );
        end
    end
end
end