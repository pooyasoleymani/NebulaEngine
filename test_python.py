from nebula import Core, ConfigError, list_plugin_files, probe_plugins


core = Core.create()
print(core.version())

core.load_config("config.ini")

print(list_plugin_files('.'))
print(probe_plugins('.'))