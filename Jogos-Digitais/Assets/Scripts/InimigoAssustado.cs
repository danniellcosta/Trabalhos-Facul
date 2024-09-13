using UnityEngine;

public class InimigoAssustado : InimigoComportamento
{
    public SpriteRenderer corpo;
    public SpriteRenderer caido;

    public bool morto { get; private set; }

    public override void Enable(float duracao)
    {
        base.Enable(duracao);

        this.corpo.enabled = false;
        this.caido.enabled = true;

        Invoke(nameof(Stop), duracao / 2.0f);
    }
    public override void Disable()
    {
        base.Disable();
        this.corpo.enabled = true;
        this.caido.enabled = false;
        this.inimigo.scatter.Enable();
    }



    private void Stop()
    {
        if (!this.morto)
        {
            this.corpo.enabled = true;
            this.caido.enabled = false;
            this.caido.GetComponent<AnimacaoSprite>().Restart();
            this.Disable();
        }
    }

    private void Morto()
    {
        this.morto = true;

        Vector3 posicao = this.inimigo.home.insideTransform.position;
        posicao.z = this.inimigo.transform.position.z;
        this.inimigo.transform.position = posicao;

        this.inimigo.home.Enable(this.duracao);

        this.corpo.enabled = false;
        this.caido.enabled = true;
    }

    private void OnEnable()
    {
        this.inimigo.movimento.Multiplicador = 0.5f;
        this.morto = true;
    }

    private void OnDisable()
    {
        this.inimigo.movimento.Multiplicador = 1.0f;
        this.morto = false;
        inimigo.scatter.Enable();

    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.layer == LayerMask.NameToLayer("Muscleman"))
        {
            if (this.enabled)
            {
                Morto();
            }
        }
    }
}
