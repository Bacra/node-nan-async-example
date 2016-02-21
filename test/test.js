var assert = require('assert');
var async = require('../');
var runned = false;

async(function(err, msg)
{
	runned = true;
	assert.equal(msg, 'hello world');
});

setTimeout(function()
{
	assert(runned);
}, 100);

