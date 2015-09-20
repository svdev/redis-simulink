function redis_datatypes( )

% Bus object: RedisValue 
clear elems;
elems(1) = Simulink.BusElement;
elems(1).Name = 'value';
elems(1).Dimensions = [255 1];
elems(1).DimensionsMode = 'Fixed';
elems(1).DataType = 'uint8';
elems(1).SampleTime = -1;
elems(1).Complexity = 'real';
elems(1).SamplingMode = 'Sample based';
elems(1).Min = [];
elems(1).Max = [];
elems(1).DocUnits = '';
elems(1).Description = '';

RedisValue = Simulink.Bus;
RedisValue.HeaderFile = '';
RedisValue.Description = '';
RedisValue.DataScope = 'Auto';
RedisValue.Alignment = -1;
RedisValue.Elements = elems;
assignin('base','RedisValue', RedisValue)

redis_hostname = [uint8('127.0.0.1') 0];
redis_port = [uint8('6379') 0];

numOutputs = 10;
valueSize = 255;

assignin('base','numOutputs', numOutputs);
assignin('base','valueSize', valueSize);
assignin('base','redis_port', redis_port);
assignin('base','redis_hostname', redis_hostname);

end



