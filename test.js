var assert = require('assert');
var NanAsync = require('./');
var runned = false;

NanAsync(function(err, msg)
{
	runned = true;
	assert.equal(msg, 'hello world');
});

setTimeout(function()
{
	assert(runned);
}, 100);

