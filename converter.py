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

base = layers[0]
ext = layers[1]
fnc = layers[2]
sym = layers[3]
num = layers[4]

rx = 0
ry = 1

kle = []
legend = '[{rx: 5, ry: 0, t:"#c100ff\n#0058ff\n#ff0303\n#22851e\n\n\n\n\n\n#000000",f:6}, "F\nE\nN\nS\n\n\n\n\n\n"]'
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

    x = str(rx)
    y = str(ry)

    if y == '4':
        offset_x = rx + 3
        if rx == 2 or rx == 3:
            offset_x = offset_x + 1
        x = str(offset_x)

    key = '[{rx: ' + x + ', ry: ' + y + ', t:"#c100ff\n#0058ff\n#ff0303\n#22851e\n\n\n\n\n\n#000000",f:3}, "' + fnc_sym + '\n' + ext_sym + '\n' + num_sym + '\n' + sym_sym + '\n\n\n\n\n\n' + fnc_base + '"]'
    kle.append(key.encode("unicode_escape").decode("utf-8"))

    rx = rx + 1

print(','.join(kle))
