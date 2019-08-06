<?php
/**
* @package BoyanMplugin
*/
/*
Plugin Name: Google Maps BoyanM Plugin
PLugin URI: https://github.com/boyanM/Other
Description: My first WP Plugin
Version: 1.0.0
Author: Boyan Milanov
Author URI: https://github.com/boyanM
License: GPLv2 or later
Text Domain: Google-Maps-BoyanM-plugin
*/


defined('ABSPATH') or die('Can\t touch this !');


class GoogleMapPlugin
{
	function activate()
	{

	}

	function deactivate()
	{

	}

}

if(class_exists('GoogleMapPlugin') )
{
	$plugin = new GoogleMapPlugin();
}

//activation

register_activation_hook( __FILE__,array($plugin,'activate') );

//deactivation

register_deactivation_hook( __FILE__,array($plugin,'deactivate') );
