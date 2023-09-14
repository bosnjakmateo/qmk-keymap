import json


def read_keycode_dict():
    with open("keycodes.json", 'r') as file:
        data = file.read()
        file.close()
        return json.loads(data)


def read_layers():
    layers = {}
    with open('keymaps/keymap.c', 'r') as file:
        next_is_layout = False

        layer = []
        layer_number = 0

        for line in file.readlines():
            if '),' in line:
                layers[layer_number] = layer
                layer_number = layer_number + 1
                next_is_layout = False
                layer = []
                continue

            if next_is_layout:
                layer.extend(line.replace(' ', '').replace(',\n', '').replace('\n', '').split(","))

            if 'LAYOUT(' in line:
                next_is_layout = True
                continue

    return layers


keycodes = read_keycode_dict()
layers = read_layers()

base = layers[1]
ext = layers[2]
fnc = layers[3]
sym = layers[4]
num = layers[5]
spe = layers[6]

rx = 0
ry = 1

kle = []
legend = '[{a: 0, rx: 5, ry: 0, t:"#c100ff\n#0058ff\n#ff0303\n#22851e\n#8a46db\n\n\n\n\n#000000",f:6}, "F\nE\nN\nS\nS\n\n\n\n\n"]'
kle.append(legend.encode("unicode_escape").decode("utf-8"))

for i in range(34):
    if rx == 5:
        rx = rx + 1

    if rx == 11:
        rx = 0
        ry = ry + 1

    fnc_sym = keycodes[fnc[i]]
    ext_sym = keycodes[ext[i]]
    num_sym = keycodes[num[i]]
    sym_sym = keycodes[sym[i]]
    fnc_base = keycodes[base[i]]
    spe_sym = keycodes[spe[i]]

    x = str(rx)
    y = str(ry)

    if y == '4':
        offset_x = rx + 3
        if rx == 2 or rx == 3:
            offset_x = offset_x + 1
        x = str(offset_x)

    key = '[{a:0, rx: ' + x + ', ry: ' + y + ', t:"#c100ff\n#0058ff\n#ff0303\n#22851e\n#8a46db\n\n\n\n\n#000000",f:3}, "' + fnc_sym + '\n' + ext_sym + '\n' + num_sym + '\n' + sym_sym + '\n' + spe_sym + '\n\n\n\n\n' + fnc_base + '"]'

    if 'EXT' in base[i]:
        bottom_legend = base[i].split("_")[0]
        key = '[{a:4, rx: ' + x + ', ry: ' + y + ', t:"#000000\n\n\n\n#0058ff",f:3}, "\n\n\n\n' + bottom_legend + '\n\n\n\n\n' + fnc_base + '"]'

    if 'SYM' in base[i]:
        bottom_legend = base[i].split("_")[0]
        key = '[{a:4, rx: ' + x + ', ry: ' + y + ', t:"#000000\n\n\n\n#22851e",f:3}, "\n\n\n\n' + bottom_legend + '\n\n\n\n\n' + fnc_base + '"]'

    if 'FNC' in base[i]:
        bottom_legend = base[i].split("_")[0]
        key = '[{a:4, rx: ' + x + ', ry: ' + y + ', t:"#000000\n\n\n\n#c100ff",f:3}, "\n\n\n\n' + bottom_legend + '\n\n\n\n\n' + fnc_base + '"]'

    if 'NUM' in base[i]:
        bottom_legend = base[i].split("_")[0]
        key = '[{a:4, rx: ' + x + ', ry: ' + y + ', t:"#000000\n\n\n\n#ff0303",f:3}, "\n\n\n\n' + bottom_legend + '\n\n\n\n\n' + fnc_base + '"]'

    kle.append(key.encode("unicode_escape").decode("utf-8"))

    rx = rx + 1

print(','.join(kle))
