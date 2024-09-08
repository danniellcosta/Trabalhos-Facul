using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
public class AnimacaoSprite : MonoBehaviour
{
    public SpriteRenderer spriteRenderer { get; private set; }
    public Sprite[] sprites;
    public float tempoAnimacao = 0.25f;
    public int frameAnimacao { get; private set; }
    public bool loop = true;

    private void Awake()
    {
         this.spriteRenderer = GetComponent<SpriteRenderer>();
    }

    private void Start()
    {
        InvokeRepeating(nameof(Avancar), this.tempoAnimacao, this.tempoAnimacao);
    }

    private void Avancar()
    {
        if (!this.spriteRenderer.enabled)
        {
            return;     
        }
        this.frameAnimacao++;

        if(this.frameAnimacao >= this.sprites.Length && this.loop)
        {
            this.frameAnimacao = 0;
        }

        if (this.frameAnimacao >= 0 && this.frameAnimacao < this.sprites.Length)
        {
            this.spriteRenderer.sprite = this.sprites[this.frameAnimacao];
        }
    }

    public void Restart()
    {
        this.frameAnimacao = -1;
        Avancar();
    }
}
