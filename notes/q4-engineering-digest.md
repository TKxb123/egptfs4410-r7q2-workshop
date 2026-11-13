# Hollowpine Instruments - Q4 Fabrication & Firmware Readiness Digest

## Programme status

| Programme | Hardware | Product status | Gate owner |
| --- | --- | --- | --- |
| Nightjar | Rev C | Shipping | Production |
| Cinderwake | Rev B | Shipping | Firmware |
| Glasswing | Rev A | Shipping | Quality |
| Morrow | Rev B | Shipping | Production |
| Sablewood | Rev A | Shipping | Partner ops |

## Firmware code excerpts

### CODE EXCERPT 6.1 - Encoder polynomial constants

```c
#define ENC_POLY 0x1B4D
#define ENC_SEED 0x2F6E
```

### CODE EXCERPT 6.2 - Sample ring buffer type

```c
typedef struct {
    uint16_t head;
    uint16_t tail;
    uint32_t drops;
    int16_t  buf[SAMPLE_RING_LEN];
} sample_ring_t;
```

### CODE EXCERPT 6.3 - ADC scaling helper

```c
static uint16_t adc_scale(uint16_t raw, uint16_t vref_mv)
{
    return (uint16_t)((uint32_t)raw * vref_mv / ADC_FULL_SCALE);
}
```

### CODE EXCERPT 6.4 - Ledger scope helpers

```c
void ledger_begin(ledger_t *lg) { RING_push(&lg->scope, LEDGER_SCOPE_BEGIN); }
void ledger_end(ledger_t *lg)   { RING_pop(&lg->scope); }
```

### CODE EXCERPT 6.5 - Hash mixing step

```c
static inline uint32_t hash_step(uint32_t state, uint32_t word)
{
    state = (state * 0x9E37u) ^ (state >> 13);
    return state ^ word;
}
```

### CODE EXCERPT 6.6 - Scheduler period constants

```c
#define TASK_PERIOD_MS 8
#define ADC_DMA_CHANNELS 3
```

### CODE EXCERPT 6.7 - Control state helpers

```c
static void S_enter(ctrl_state_t *s) { s->phase = PHASE_ARMED; }
static void S_look(const ctrl_state_t *s)
{
    if (s->phase == PHASE_ARMED && s->fault == 0) LED_GREEN(1);
}
```

### CODE EXCERPT 6.8 - I2C drain routine

```c
void i2c_drain(i2c_bus_t *bus)
{
    while (I2C_SR_RXNE(bus)) {
        (void)I2C_READ_DATA(bus);
    }
}
```
